#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,c[505],pas[505],ans;
char tg[505];
bool cmp(ll x,ll y)
{
	return x<y;
}
ll jie(ll x)
{
	ll sum=1;
	for (ll i=1;i<=x;i++)
		sum=sum*i%mod;
	return sum;
}
void dfs(ll step,ll tf[],ll nop)
{
	if (nop+m>n)
		return;
	if (step>n && nop+m<=n)
		ans=(ans+1)%mod;
	for (ll i=1;i<=n;i++)
	{
		ll flag=0;
		if (c[i]<=nop)
		{
			ll sum=0;
			for (ll j=i;j<=n;j++)
				if (!tf[j])
				{
					sum++;
					if (sum+nop+m>n)
						break;
				}
			if (sum+nop+m<=n)
			{
				ans=(ans+jie(sum)%mod)%mod;
				flag=1;
			}
		}
		if (flag)
			break;
		if (!tf[i])
		{
			tf[i]=1;
			dfs(step+1,tf,nop+(pas[step]==0 || c[i]<=nop));
			tf[i]=0;
		}
	}
}
int main(){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,tg);
	sort(c+1,c+n+1,cmp);
	for (ll i=0;i<n;i++)
		pas[i+1]=tg[i];
	ll tf[505];
	memset(tf,0,sizeof(tf));
	dfs(1,tf,0);
	printf("%lld",ans+1);
	return 0;
	}

