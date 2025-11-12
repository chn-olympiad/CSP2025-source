#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point {
	ll u,v,w;
	const bool operator <(const point &k)const
	{
		return w>k.w;
	}
};
ll n,m,k,fa[10005],ca[15][10005],c[15],ans=1e10;
ll ua[1000005],va[1000005],wa[1000005];
ll find(ll x)
{
	if (fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
priority_queue<point> q;
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (ll i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&ua[i],&va[i],&wa[i]);
		q.push({ua[i],va[i],wa[i]});
	}
	for (ll i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for (ll j=1;j<=n;j++)
			scanf("%lld",&ca[i][j]);
	}
	for (ll i=0;i<=1<<k;i++)
	{
		for (ll i=1;i<=n;i++)
			fa[i]=i;
		ll sum=0;
		for (ll j=1;j<=k;j++)
			if ((1<<j)&i)
			{
				sum+=c[j];
				for (ll l=1;l<=n;l++)
					for (ll r=l+1;r<=n;r++)
						q.push({l,r,ca[j][l]+ca[j][r]});
			}
		while (!q.empty())
		{
			ll u=q.top().u,v=q.top().v,w=q.top().w;
			q.pop();
			ll from=find(u),to=find(v);
			if (from!=to)
				fa[from]=to,sum+=w;
		}
		if (sum<=ans)
			ans=min(ans,sum);
		for (ll j=1;j<=m;j++)
			q.push({ua[j],va[j],wa[j]});
	}
	printf("%lld",ans);
	return 0;
	}

