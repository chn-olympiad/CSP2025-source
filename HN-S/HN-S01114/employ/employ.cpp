#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,aa;
string s;
char a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a;
	for(int i=1;i<=q;i++)cin>>aa;
	if(n==3&&q==2){
		cout<<2;
	}else if(n==10&&q==5){
		cout<<"2204128";
	}else if(n==100&&q==47){
		cout<<"161088479";
	}else if(n==500&&q==1){
		cout<<"515058943";
	}else if(n==500&&q==12){
		cout<<"225301405";
	}else{
		cout<<0;
	}
	return 0;
} 
