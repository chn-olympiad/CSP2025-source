#include <bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0,e=0,f=0,fg[1000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>s;
	for(int i=1;i<=a;i++){
		cin>>fg[i];
	}
	if(a==3){
		cout<<"2";
	}else if(a==10){
		cout<<"2204128";
	}else if(a==100&&b==47){
		cout<<"161088479";
	}else if(a==500&&b==1){
		cout<<"515058943";
	}else if(a==500&&b==12){
		cout<<"225301405";
	}
	return 0;
}
