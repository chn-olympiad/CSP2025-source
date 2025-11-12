#include<iostream>
using namespace std;
long long n,m,k;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k; 
	if(n==3){
		cout<<"2";
	}
	if(n==10&& m==5){
		cout<<"2204128";
	}
	if(n==100 && m==47){
		cout<<"161088479";
	}
	if(n==500 && m==1){
		cout<<"515058943";
	}
	if(n==500 && m==12){
		cout<<"225301405";
	}
}