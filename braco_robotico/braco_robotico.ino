#include <Servo.h> //BIBLIOTECA DE FUNÇÕES COM MOTORES SERVOS

 // DECLARAÇÃO DOS MOTORES UZADOS NO PROJETO...
  Servo servoEsq; //RODA ESQUERDA DA BASE DO BRAÇO...
  Servo servoDir;  //RODA DIREITA...
  Servo servoGarra;   //GARRA DO B RAÇO MECÂNICO...
  Servo servoBraco;  //MOTOR RESPONSÁVEL PELA MOVIMENTAÇÃO VERTICL DO BRAÇO...
  Servo servoBraco2;
 
  int posicaoBraco = 0;
  int posicaoGarra = 80;
 
void setup() //FUNÇÃO ONDE SÃO ESPECIFICADAS AS CONFIGURAÇÕES DO PROJETO...
{
  //ATRIBUIÇÃO DE PINOS PARA OS MOTORES
  servoGarra.attach(3);
  servoBraco.attach(5);
  servoBraco2.attach(6);
  servoEsq.attach(9);
  servoDir.attach(10);
  Serial.begin(9600);
}

void parado() //FUNÇÃO QUE MANTÉN OS DOIS SERVOS DE ROTAÇÃO CONTÍNUA USADOS NAS RODAS PARADOS (ROBÔ PARADO)...
{
    servoDir.write(87);
    servoEsq.write(90);
}
void direita() //FUNÇÃO RESPONSÁVEL POR GIRAR A BASE PARA A DIREITA...
{
    servoEsq.write(0);
    servoDir.write(0);
    delay(1300); //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX.90 GRAUS E PARA...
    parado();
}

void esquerda()  //FUNÇÃO RESPONSÁVEL POR GIRAR A BASE PARA A ESQUERDA...
{
    servoEsq.write(180);
    servoDir.write(180);
    delay(1300);   //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX. 90 GRAUS E PARA...
    parado();
}

void sobeBraco() // FUNÇÃO RESPONSÁVELPORLEVANTAR O BRAÇO MECÂNICO...
{
  int i;
  for( i = posicaoBraco;i<90;i++)
  {
      servoBraco.write(180-i);
      servoBraco2.write(i);
      delay(45);
  }
  posicaoBraco = i;
}

void baixaBraco() //FUNÇÃO RESPONSÁVEL POR BAIXAR O BRAÇO MECÂNICO...
{
  int i;
  for(i = posicaoBraco; i > 0;i--)
  {
      servoBraco.write(180-i);
      servoBraco2.write(i);
      delay(45);
  }
  posicaoBraco = i;
}

void abre() // FUNÇÃO QU ABRE A GARRA...
{
   int i;
  for(i = posicaoGarra; i < 160;i++)
  {
      servoGarra.write(i);
      delay(40);
  }
  posicaoGarra = i;
}

void fecha()  // FUNÇÃO QU FECHA A GARRA...
{
   int i;
  for(i = posicaoGarra; i > 80;i--)
  {
      servoGarra.write(i);
      delay(40);
  }
  posicaoGarra = i;
}


void loop()
{
    char tecla = Serial.read(); // A PORTA SERIAL LÊ UMA TECLA DIGITADA NO TECLADO DO COMPUTADOR...
                                //E DE ACORDO COM O CARACTER LIDO CHAMA UMA DAS FUNÇÕES ACIMA...
   
    if(tecla == 'd' || tecla == 'D') //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A DIREITA...
    {
      direita();
    }
    else if(tecla == 'e' || tecla == 'E') //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A ESQUERDA...
    {
      esquerda();
    }
   
    else if (tecla == 'a' || tecla == 'A') //CASO PRESSIONE A TECLA 'A', O ROBO ABRE A GARRA...
    {
       abre();
    }
    else if(tecla == 'f' || tecla == 'F') //CASO PRESSIONE A TECLA 'F', O ROBO FECHA A GARRA...
    {
      fecha();
    }
    else if (tecla == 's' || tecla == 'S') //CASO PRESSIONE A TECLA 'S', O ROBO SOBE O BRAÇO...
    {
        sobeBraco();
    }
    else if (tecla == 'b' || tecla == 'B') //CASO PRESSIONE A TECLA 'B', O ROBO BAIXA O BRAÇO...
    {
       baixaBraco();
    }
   
    else // CASO NÃO PRESSIONE NENHUMA TECLA O ROBÔ PERMANECE PARADO...
    {
        parado();
    }
}

