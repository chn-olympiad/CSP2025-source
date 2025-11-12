#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5,M=1e6+5,K=15;
struct node
{
	ll u,v,w;
 };
vector<node> e;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll n,m,k,fa[N+K],cost[K],vw[15][N];
ll find(ll x)
{
	return fa[x]==x?x:find(fa[x]);
}
void merge(ll x,ll y)
{
	fa[find(x)]=find(y);
}
ll kruskal()
{
	sort(e.begin(),e.end(),cmp);
	for(ll i=1;i<=n;i++)
		fa[i]=i;
	ll ans=0,cnt=0;
	for(ll i=0;i<e.size();i++)
	{
		if(find(e[i].u)==find(e[i].v))
			continue;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1)
			break;
		merge(e[i].u,e[i].v);
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	bool ia=1;
	for(ll i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		e.push_back({u,v,w});
	}
	for(ll i=1;i<=k;i++)
	{
		scanf("%lld",&cost[i]);
		if(cost[i]!=0)
			ia=0;
		for(ll j=1;j<=n;j++)
		{
			scanf("%lld",&vw[i][j]);
			if(vw[i][j]!=0)
				ia=0;
		}
	}
	if(ia)
	{
		printf("0");
		return 0;
	}
	printf("%lld",kruskal());
	return 0;
}

