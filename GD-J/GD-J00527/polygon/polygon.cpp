#include<iostream>
#include<cstdio>
using namespace std;
int n,q[10086],maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		maxn=max(maxn,q[i]);
		if(q[i]!=1) f=0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}if(n==3){
		if(q[1]+q[2]+q[3]<maxn*2){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}
	if(f){
		long long sum=0;
		for(int i=n-3;i>=1;i--){
			sum+=(1+i)*i/2;
			sum%=998244353;
		}
		cout<<sum%998244353;
		return 0;
	}
}
