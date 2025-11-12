#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],w[5005],dp[10005],sum[5005][10005],s[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<=2*a[n];i++)
	{
		sum[0][i]=1;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=a[i];j<=2*a[n];j++)
		{
			dp[j]=sum[i-1][j-a[i]];
			dp[j]=dp[j]%mod;
		}
		s[i]=dp[2*a[i]];
		for(long long j=a[i+1];j<=2*a[n];j++)
		{
			sum[i][j-a[i+1]]=sum[i-1][j-a[i+1]]+dp[j-a[i+1]];
			sum[i][j]=sum[i][j]%mod;
		}
		memset(dp,0,sizeof(dp));
	}
	w[1]=1;
	for(long long i=2;i<=n;i++)
	{
		w[i]=w[i-1]*2;
		w[i]=w[i]%mod;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		ans+=(w[i]-s[i]+mod)%mod;
		ans=ans%mod;
	}
	cout<<ans%mod;
	return 0;
}