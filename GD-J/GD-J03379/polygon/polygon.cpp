#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
const ll mod=998244353;
int n,a[N],maxn;
ll dp[N],sum[N],ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=0;i<=maxn;i++) sum[i]=1;
	ll pw=1;
	for(int i=1;i<=n;i++,pw=pw*2ll%mod)
	{
		ll cnt=(pw-sum[a[i]]+mod)%mod;
		ans=(ans+cnt)%mod;
		for(int j=maxn;j>=0;j--)
			if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		for(int j=1;j<=maxn;j++)
			sum[j]=(sum[j-1]+dp[j])%mod;
	}
	printf("%lld",ans);
	return 0;
}
//Please CSP-S2025 1= QwQ!!! 
