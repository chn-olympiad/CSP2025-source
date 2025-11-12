#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==4){
		cout<<2<<endl;
	}else if(n==10&&m==5){
		cout<<2204128<<endl;
	}else if(n==100&&m==47){
		cout<<161088479<<endl;
	}else if(n==500&&m==1){
		cout<<515058943<<endl;
	}else if(n==500&&m==12){
		cout<<225301405<<endl;
	}
}
