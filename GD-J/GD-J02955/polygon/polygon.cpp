#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5010],ans,dp[5010];
long long ksm(long long d,long long z)
{
	long long ret=1;
	while(z)
	{
		if(z&1)
		{
			ret*=d;
			ret%=mod;
		}
		z>>=1;
		d*=d;
		d%=mod;
	}
	return ret;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ans=(ksm(2,n)-1+mod)%mod;
	dp[0]=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=a[i];j>=0;j--)
		{
			ans=(ans-dp[j]+mod)%mod;
		}
		for(long long j=a[n]-a[i];j>=0;j--)
		{
			dp[a[i]+j]=(dp[j]+dp[a[i]+j])%mod;
		}
	}
	printf("%lld",ans);
}
