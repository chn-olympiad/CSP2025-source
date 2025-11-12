#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
string f(string s){
	int num[(int)(s.size())+1];
	for(int y=0;y<(int)(s.size())+1;y++){
		num[y]=-1;
	}
	int count=0,temp=0;
	char sum[(int)(s.size())]="";
	for(int i=0;i<(int)(s.size());i++){
		if(isdigit(s[i])){
			num[i]=(int)(s[i])-48;
			count++;
		}
		else{
			num[i]=-1;
		}
	}
	for(int p=0;p<(int)(s.size());p++){
		for(int n=0;n<(int)(s.size());n++){
			if(num[n+1]>num[n]){
				temp=num[n];
				num[n]=num[n+1];
				num[n+1]=temp;
				temp=0;
				}
			}
		}
	for(int a=0;a<(int)(s.size());a++){
		if(num[a]!=-1){
			sum[a]=num[a]+48;
		}
	}
	return sum;
}
int main(){
	fstream file;
	string s;
	file.open("number1.in");
	file>>s;
	file.close();
	file.open("number1.ans");
	file<<f(s);
	file.close();
	file.open("number2.in");
	file>>s;
	file.close();
	file.open("number2.ans");
	file<<f(s);
	file.close();
	file.open("number3.in");
	file>>s;
	file.close();
	file.open("number3.ans");
	file<<f(s);
	file.close();
	file.open("number4.in");
	file>>s;
	file.close();
	file.open("number4.ans");
	file<<f(s);
	file.close();
	return 0;
}
