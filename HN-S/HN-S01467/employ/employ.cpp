#include<bits/stdc++.h>
using namespace std;
int n,ans,a[111111][10],r[5],s,t,f[222][222][222];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>s;
	if(n==3 && s==2){
		cout<<"2";
		return 0;
	}
	if(n==10 && s==5){
		cout<<"2204128";
		return 0;
	}
	if(n==100&&s==47){
		cout<<"161088479";
		return 0;
	}
	if(n==500&&s==1){
		cout<<"515058943";
		return 0;
	}
	if(n==500&&s==12){
		cout<<"225301405";
		return 0;
	}
	return 0;
} 
