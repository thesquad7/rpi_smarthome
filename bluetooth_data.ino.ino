 
#include <SoftwareSerial.h> 
#include <Servo.h>
SoftwareSerial module_bluetooth(0, 1); // pin RX | TX
 
char data = 0;
Servo myservo; 
Servo myservo2;              
void setup() 
{
  Serial.begin(9600);         
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  myservo.attach(12);
  myservo2.attach(13);
    //inisialisasi LED menjadi output
}
void loop()
{
  if(Serial.available() > 0)  
  {
    data = Serial.read();Serial.print(data);    //Pembacaan dan ditampilkan data yang masuk   
    Serial.print("\n"); 
    //Data yang masuk      
    switch (data) {
      //LAMPU LANTAI BAWAH
  case '1':
    digitalWrite(2, HIGH);
    break;
  case '2':
    digitalWrite(3, HIGH);
    break;
  case '3':
    digitalWrite(4, HIGH);
    break;
  case '4':
    digitalWrite(5, HIGH);
    break;
  case '5':
    digitalWrite(6, HIGH);
    break;
  case 'A':
    digitalWrite(2, LOW);
    break;
  case 'B':
    digitalWrite(3, LOW);
    break;
  case 'C':
    digitalWrite(4, LOW);
    break;
  case 'D':
    digitalWrite(5, LOW);
    break;
  case 'N':
    digitalWrite(6, LOW);
    break;
//==============================================
    //LAMPU LANTAI ATAS
  case '6':
    digitalWrite(7, HIGH);
    break;
  case '7':
    digitalWrite(8, HIGH);
    break;
  case '8':
    digitalWrite(9, HIGH);
    break;
  case '9':
    digitalWrite(10, HIGH);
    break;
  case 'Z':
    digitalWrite(11, HIGH);
    break;
  case 'E':
    digitalWrite(7, LOW);
    break;
  case 'F':
    digitalWrite(8, LOW);
    break;
  case 'G':
    digitalWrite(9, LOW);
    break;
  case 'H':
    digitalWrite(10, LOW);
    break;
  case 'I':
    digitalWrite(11, LOW);
    break;
                                
//==============================================
    //DOOR
  case 'P':
    myservo.write(-180);
    myservo2.write(-180);
    break;
  case 'Q':
    myservo.write(180);
    myservo2.write(180);
    break;
    }
  }
}
