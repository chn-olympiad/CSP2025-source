#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 1e5+5;
const lld mod = 998244353;
using pll = pair<lld,lld>;

lld n,ans;
lld a[siz],cho[siz];
void dfs(lld now,lld sum)
{
	if(now>n)
	{
		if(sum > 2)
		{
			lld mx = 0,s = 0;
			for(int i=1;i<=n;i++)
			{
				if(cho[i])
				{
					mx = max(mx,a[i]);
					s+=a[i];
				}
			}
			if(s>mx*2)
				ans++;
		}
		return ;
	}
	cho[now] = 1;
	dfs(now+1,sum+1);
	cho[now] = 0;
	dfs(now+1,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=25)
	{
		dfs(1,0); printf("%lld",ans);
	}
	else
	{
		lld x = 1,y = n,z = n*(n-1)/2;
		for(int i=1;i<=n;i++)
			{ x*=2; x%=mod; }
		printf("%lld",(x-y-z+2*mod)%mod-1);
	}
	return 0;
}
