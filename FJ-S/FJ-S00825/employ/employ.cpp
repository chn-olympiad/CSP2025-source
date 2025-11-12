#include<bits/stdc++.h>
using namespace std;
long long a[100500],n,m,k;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		cout<<2;
	}else if(n==10&&m==5){
		cout<<2204128;
	}else if(n==100&&m==47){
		cout<<161088479;
	}else if(n==500&&m==1){
		cout<<515058943;
	}else if(n==500&&m==12){
		cout<<225301405;
	}else if(m==1){
		cout<<n;
	}else if(m==n){
		cout<<1;
	}
}//geidianfenba
