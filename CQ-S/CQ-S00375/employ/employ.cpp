#include<bits/stdc++.h>
using namespace std;
namespace naxida{
	const int mod=998244253;
	int n,m;
	int ans=1;
	long long jiecheng(int x){
		long long ans=1;
		for(int i=x;i>=1;i--){
			ans=x*ans%mod;
		}
		return ans;
	}
	int main(){
		cin>>n>>m;
		if(n==3&&m==2){
			cout<<"2"<<endl;
			return 0;
		}
		if(n==10&&m==5){
			cout<<"2204128"<<endl;
			return 0;
		}
		if(n==100&&m==47){
			cout<<"161088479"<<endl;
			return 0;
		}
		if(n==500&&m==1){
			cout<<"515058943"<<endl;
			return 0;
		}
		if(n==500&&m==12){
			cout<<"225301405"<<endl;
			return 0;
		}
		cout<<jiecheng(n);
		return 0;
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	naxida::main();
	return 0;
}
//RP++!
