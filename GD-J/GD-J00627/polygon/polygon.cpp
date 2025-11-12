#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],ans=0;
void dfs(ll x,ll sum,ll mx)
{
	if(x>n)
	{
		if(sum>2*mx)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(x+1,sum+a[x],max(mx,a[x]));
	dfs(x+1,sum,mx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
