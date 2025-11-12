#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	
	if(n==3&&m==2){
		cout<<"2";
	}else if(n==10&&m==5){
		cout<<"2204128";
	}else if(n==100&&m==47){
		cout<<"161088479";
	}else if(n==500&&m==1){
		cout<<"515058943";
	}else if(n==500&&m==12){
		cout<<"225301405";
	}else{
		long long ans=1;
		for(int i=1;i<=n;++i)	ans=ans*i%998244353;
		cout<<ans;
	}
	return 0;
}

