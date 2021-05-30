int EN1 = 6;
int EN2 = 5;
int IN1 = 7;
int IN2 = 4;

int speed = 150;
int FrontLedPin = 13;
int BackLedPin = 14;
int buzPin = 8;

void Motor1(int pwm, boolean reverse)
{
  //analogWrite(EN1, pwm);
  if(reverse)
  {
    digitalWrite(IN1, HIGH);
    analogWrite(EN1, 9-pwm);
  } else
  {
    digitalWrite(IN1, LOW);
    analogWrite(EN1, pwm);
  }
}

void Motor2(int pwm, boolean reverse)
{
//  analogWrite(EN2, pwm);
  if(reverse)
  {
    digitalWrite(IN2, HIGH);
    analogWrite(EN2, 9-pwm);
  } else
  {
    digitalWrite(IN2, LOW);
    analogWrite(EN2, pwm);
  }
}

void setup()
{
  int i;
  for(i=4; i<= 7; i++)
    pinMode(i, OUTPUT);
  Serial.begin(115200);
  pinMode(FrontLedPin, OUTPUT);
  pinMode(BackLedPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
}

void loop()
{
  int x, dealy_en;
  char val;
  while(1)
  {
    val = Serial.read();
    if(val !=-1)
    {       
       switch(val)
       {
         case '0': speed = 0;
                    break;
         case '1': speed = 0;
                    break;
         case '2': speed = 100;
                    break;
         case '3': speed = 120;
                    break;
         case '4': speed = 140;
                    break;
         case '5': speed = 160;
                    break;
          case '6': speed = 180;
                    break;
          case '7': speed = 200;
                    break;   
          case '8': speed = 220;
                    break;
          case '9': speed = 240;
                    break;
          case 'a': speed = 255;
                    break;       
         case 'l': // GO
                    Motor1(speed, true);
                    Motor2(speed, true);
                    break;
         case 'r': // Back
                    Motor1(speed, false);
                    Motor2(speed, false);
                    break;
         case 'f': // Right
                    Motor1(speed, false);
                    Motor2(speed, true);
                    break;
         case 'b': // Left
                    Motor1(speed, true);
                    Motor2(speed, false);
                    break;
          case 'g': // Left GO
                    Motor1(speed, true);
                    Motor2(0, false);
                    break;
          case 'i': // Right GO
                    Motor1(0, false);
                    Motor2(speed, true);
                    break;
          case 'j': // Left Back
                    Motor1(speed, false);
                    Motor2(0, true);
                    break;
          case 'h': // Right Back
                    Motor1(0, true);
                    Motor2(speed, false);
                    break;
         case 's': // Stop
                    Motor1(0, false);
                    Motor2(0, false);
                    break;
         case 'W': // Front Light ON
                    digitalWrite(FrontLedPin, HIGH);
                    break;
         case 'w': // Front Light OFF
                    digitalWrite(FrontLedPin, LOW);
                    break;
         case 'U': // Back Light ON
                    digitalWrite(BackLedPin, HIGH);
                    break;
         case 'u': // Back Light OFF
                    digitalWrite(BackLedPin, LOW);
                    break;
         case 'Z': // buzzer ON
                    digitalWrite(buzPin, HIGH);
                    break;
         case 'z': // buzzer OFF
                    digitalWrite(buzPin, LOW);
                    break;
         default:   
                    Motor1(0, false);
                    Motor2(0, false);
                    break;
       }
    }
  }
}  
                    