#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],m;
long long dp[5005],d[5005],c[5005];
long long mod=998244353,k,s;
long long qpow(long long a,long long b){
	if(b==0)return 1;
	if(b==1)return a;
	long long s=qpow(a,b>>1);
	s=s*s%mod;
	if(b&1)s=s*a%mod;
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);c[0]=1;d[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);m=max(m,a[i]);
		c[i]=c[i-1]*i%mod;d[i]=qpow(c[i],mod-2);
	}
	sort(a+1,a+1+n);dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)k+=dp[j];
		for(int j=m;j>=a[i];j--)dp[j]=(dp[j-a[i]]+dp[j])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		s=(s+c[n]*d[n-i]%mod*d[i]%mod)%mod;
	}
	printf("%lld",(s-k+mod)%mod);
	return 0;
}

