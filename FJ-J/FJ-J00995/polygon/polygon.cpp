#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,a[5005],ans;
ll po(ll b,ll m)
{
	ll ans=1,base=b;
	while (m)
	{
		if (m&1)
			ans*=base;
		base*=base;
		m>>=1;
	}
	return ans;
}
void dfs(ll step,ll sum)
{
	if (sum>a[n] && step>=3 && step!=n)
	{
		ans=(ans+po(2,n-step+1)-1)%mod;
		return;
	}
	if (sum>a[step] && step>=3)
		ans=(ans+1)%mod;
	if (step<n)
	{
		dfs (step+1,sum+a[step]);
		dfs (step+1,sum);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort (a+1,a+n+1);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
	}

