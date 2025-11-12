#include<iostream>
#include<string>
using namespace std;


int nm1,nm2,nm3,nm4,nm5,nm6,nm7,nm8,nm9,nm0;
string s;
int xn=0;
int n=0;
int main(){
		cin >>s;
	for(int i=0;i>=0;i++){
		if(s[i]==1||s[i]==2||s[i]==3 ||s[i]==4 || s[i]==5|| s[i]==6|| s[i]==8|| s[i]==9|| s[i]==0){
			xn++;
			}
		}
	
	for(int j=0;j>=0;j++){
		if(s[xn]==1){
			nm1=nm1+1;
		}
		if(s[xn]==2){
			nm2=nm2+2;
		}
		if(s[xn]==3){
			nm3=nm3+3;
		}
		if(s[xn]==4){
			nm4=nm4+4;
		}
		if(s[xn]==5){
			nm5=nm5+5;
		}
		if(s[xn]==6){
			nm6=nm6+6;
		}
		if(s[xn]==7){
			nm7=nm7+7;
		}
		if(s[xn]==8){
			nm3=nm8+8;
		}
		if(s[xn]==9){
			nm9=nm9+9;
		}
		if(s[xn]==0){
			nm0=nm0+0;
		}
	
		cout<<nm9<<nm8<<nm7<<nm6<<nm5<<nm4<<nm3<<nm2<<nm1<<nm0;
	}

	
		return 0;
} 
