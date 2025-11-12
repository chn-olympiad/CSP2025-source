#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ma,ans,mod=998244353,fac[5001],inv[5001];
long long dfs(int s,long long sum,long long m,int l){
	if(s==0)return (sum>m*2)?1:0;
	int t=0;
	for(int i=l;i<=n-s+1;i++)t=(t+dfs(s-1,sum+a[i],max(m,a[i]),i+1))%mod;
	return t;
}
long long fastpow(int a,int b,int c){
	long long r=1;
	while(b){
		if(b&1)r=(r*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return r;
}
long long C(int l,int r){
	if(l>r)return 0;
	return fac[r]*inv[l-1]%mod*inv[l]%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]);
	if(ma==1){
		fac[0]=1;
		for(int i=1;i<=n;i++)fac[i]=(fac[i-1]*i)%mod;
		for(int i=1;i<=n;i++)inv[i]=fastpow(fac[i],mod-2,mod);
		for(int i=3;i<=n;i++)ans=(ans+C(i,n))%mod;
		return 0;
	}
	for(int i=3;i<=n;i++)ans=(ans+dfs(i,0,0,1))%mod;
	cout<<ans;
	return 0;
}
