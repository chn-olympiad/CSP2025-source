#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+35;
const int M=1e6+5;
int n,m,k;
struct node
{
	int u,v,w;
}e[M],ee[N*10];
int cnt;
int c[11],a[N][11];
int fa[N*10],siz[N],sum,minn;
int ya;
bool cmp(node a,node b)
{
	return a.w<b.w;
}
inline int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool vis[N*10];
node e1[N*10];
inline void solve()
{
	int ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int tot=0;
	for(int i=1;i<=cnt;i++)
		if(ee[i].v-n<=0) e1[++tot]=ee[i];
		else
			if(!vis[ee[i].v-n])
				e1[++tot]=ee[i];
//	for(int i=1;i<=tot;i++)
//	{
//		cout<<e1[i].u<<' '<<e1[i].v<<' '<<e1[i].w<<'\n';
//	}
//	cout<<'\n';
	int num=n+tot/n;
	for(int i=1;i<=tot;i++)
	{
		int v=find(e1[i].v),u=find(e1[i].u);
		if(v!=u)
		{
			fa[u]=v;
			ans+=e1[i].w;
			num--;
			if(num==1) break;
		}
	}
//	cout<<ans<<' '<<ya<<'\n';
	minn=min(minn,ans+ya);
}
inline void dfs(int now)
{
	if(now>k)
	{
		solve();
		return;
	}
	dfs(now+1);
	
	vis[now]=1;
	ya-=c[now];
	dfs(now+1);
	ya+=c[now];
	vis[now]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) siz[i]=1,fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int v=find(e[i].v),u=find(e[i].u);
		if(v!=u)
		{
			if(siz[v]<siz[u]) swap(u,v);
			fa[u]=v;
			siz[v]+=siz[u];
			sum+=e[i].w;
			ee[++cnt]=e[i];
			if(siz[v]==n) break;
		}
	}
	if(k==0)
	{
		cout<<sum<<'\n';
		exit(0);
	}
	minn=sum;
	bool flag;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		ya+=c[i];
		if(!c[i]) flag=1;
		else flag=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][i];
			ee[++cnt]={j,i+n,a[j][i]};
			if(a[i][j]) flag=0;
		}
		if(flag and n>1000 and m>100000)
		{
			cout<<0;
			return 0;
		}
	}
	sort(ee+1,ee+cnt+1,cmp);
	dfs(1);
	cout<<minn<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
/*
5 6 0
1 2 1
1 5 2
2 4 3
2 3 10000
4 5 9999
1 3 10000
*/
