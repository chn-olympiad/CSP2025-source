#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis[500005],c[500005],now,n,m,k,cnt,nn,ans=2e17;
struct node
{
	int u,v,w;
}e[1090005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int f[1000005];
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}
void check()
{
	int ct=0,as=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(u>n)
		{
			if(!vis[u-n]) continue;
		}
		if(v>n)
		{
			if(!vis[v-n]) continue;
		}
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		ct++;
		as+=w;
		if(ct==nn-1) break;
	}
	ans=min(ans,as+now);
}
void dfs(int x)
{
	if(x==k+1)
	{
		check();
		return;
	}
	vis[x]=1;nn++;now+=c[x];
	dfs(x+1);
	vis[x]=0,nn--;now-=c[x];
	dfs(x+1);
}
signed main()//wo xi wang wo neng zou jin NOIP kao chang
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;nn=n;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt].u=u,e[cnt].v=v,e[cnt].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			e[++cnt].u=i+n,e[cnt].v=j,e[cnt].w=x;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
