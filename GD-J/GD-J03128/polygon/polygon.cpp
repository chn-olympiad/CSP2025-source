#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll m=0,ans=0;
ll n,a[5005];
ll dp[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		m=max(m,a[i]+1);
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(ll i=1;i<n;i++)
	{
		for(ll j=m;j>=a[i];j--)
		{
			if(j==m)
			{
				for(ll k=m;k>=m-a[i];k--)dp[j]=(dp[j]+dp[k])%mod;
			}
			else dp[j]=(dp[j]+dp[j-a[i]])%mod;
		} 
		for(ll j=a[i+1]+1;j<=m;j++)ans=(ans+dp[j])%mod;
		//for(ll j=1;j<=m;j++)cout<<dp[j]<<' ';
		//cout<<'\n';
	}
	printf("%lld\n",ans%mod);
	
	return 0;
}
