#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	if(n==3){
		cout<<1;
		return 0;
	}
	if(n==4){
		cout<<5;
	}
	if(n==5){
		cout<<16;
	}
	int fac[n]={0,1,2};
	for(int i=3;i<=n;i++)fac[i]=fac[i-1]*i;
	long long ans=n+1+fac[n-1]/4;
	for(int i=3;i<=n/2;i++){
		ans=(ans+fac[n-1]/fac[i-1]*2)%998244353;
	}
	cout<<ans;
	return 0;
}
 
