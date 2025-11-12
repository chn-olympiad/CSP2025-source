#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
#define f first
#define s second
using namespace std;
ll n,m,k,ans=LLONG_MAX,mst,c[15];
ll a[15][10005],f[10025];
vector<pii> e[110005];
bool b[10025];
priority_queue<pii> q;
void dij(ll x,ll g)
{
	for(ll i=0;i<=n+x;i++) f[i]=INT_MAX,b[i]=0;
	f[1]=mst=0;
	q.push({0,1});
	while(!q.empty())
	{
		ll x=q.top().s;
		q.pop();
		if(b[x]) continue;
		b[x]=1;
		mst+=f[x];
		for(pii i : e[x])
		{
			if(!b[i.f]&&f[i.f]>i.s)
			{
				f[i.f]=i.s;
				q.push({-f[i.f],i.f});
			}
		}
	}
	ans=min(ans,mst+g);
}
void dfs(ll x,ll id,ll g)
{
	if(id>k) return ;
	dij(x,g);
	for(ll i=id+1;i<=k;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			e[j].push_back({n+x+1,a[i][j]});
			e[n+x+1].push_back({j,a[i][j]});
		}
		dfs(x+1,i,g+c[i]);
		e[n+x+1].clear();
		for(ll j=1;j<=n;j++) e[j].pop_back();
	}
}
ll rd()
{
	char ch=getchar();
	ll x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(ll i=1,u,v,w;i<=m;i++)
	{
		u=rd(),v=rd(),w=rd();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++)
	{
		c[i]=rd();
		for(ll j=1;j<=n;j++) a[i][j]=rd();
	}
	dfs(0,0,0);
	printf("%lld",ans);
	return 0;
}
