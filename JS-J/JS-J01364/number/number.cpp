#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	
	freopen("number.in","R",stdin);
	freopen("number.out","W",stdout);
	string a;
	int d0=0,d1=0,d2=0,d3=0,d4=0,d5=0,d6=0,d7=0,d8=0,d9=0;
	int b=a.length();
	cin>>a;
	for(int i=0;i<b;i++){
		if(a[i]=="0"){
			d0++;
		}
		if(a[i]=="1"){
			d1++;
		}
		if(a[i]=="2"){
			d2++;
		}
		if(a[i]=="3"){
			d3++;
		}
		if(a[i]=="4"){
			d4++;
		}
		if(a[i]=="5"){
			d5++;
		}
		if(a[i]=="6"){
			d6++;
		}
		if(a[i]=="7"){
			d7++;
		}
		if(a[i]=="8"){
			d8++;
		}
		if(a[i]=="9"){
			d9++;
		}
	}
	for(int i=1;i<=d9;i++){
		cout<<9;
	}
	for(int i=1;i<=d8;i++){
		cout<<8;
	}
	for(int i=1;i<=d7;i++){
		cout<<7;
	}
	for(int i=1;i<=d6;i++){
		cout<<6;
	}
	for(int i=1;i<=d5;i++){
		cout<<5;
	}
	for(int i=1;i<=d4;i++){
		cout<<4;
	}
	for(int i=1;i<=d3;i++){
		cout<<3;
	}
	for(int i=1;i<=d2;i++){
		cout<<2;
	}
	for(int i=1;i<=d1;i++){
		cout<<1;
	}
	for(int i=1;i<=d0;i++){
		cout<<0;
	}
	return 0;
}
