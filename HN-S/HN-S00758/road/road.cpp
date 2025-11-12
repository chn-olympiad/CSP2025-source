#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e16;
struct edge{
	int u,v,w;
}e[N];
int c[N],vis[N],fa[N];
int n,m,k,tot=0;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void init()
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int Kruskal(int x)
{
	int cnt=n,ans=0;
	for(int i=1;i<=k;i++)
	{
		if(x>>(i-1)&1)
		{
			vis[i+n]=1;
			cnt++;
			ans+=c[i];
		}
		else vis[i+n]=0;
	}
	init();
	for(int i=1;i<=tot;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(vis[u]==0||vis[v]==0) continue;
		int fau=find(u),fav=find(v);
		if(fau==fav) continue;
		fa[fau]=fav;
		ans+=e[i].w;
		cnt--;
		if(cnt==1) return ans;
	}
	return ans;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) vis[i]=1;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	tot=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			tot++;
			cin>>e[tot].w;
			e[tot].u=n+i,
			e[tot].v=j;
		}
	}
	sort(e+1,e+tot+1,cmp);
	int ans=inf;
	for(int i=0;i<(1<<k);i++)
	{
		ans=min(Kruskal(i),ans);
	}
	cout<<ans<<'\n';
	return 0;
}

