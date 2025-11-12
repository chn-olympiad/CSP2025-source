#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
struct edge
{
	int to,from,dis;
}e[10000001];
int n,m,k,c[11],tot,d[11][10001],fa[10001],cnt,ans;
inline void add(int u,int v,int w)
{
	e[++tot].from=u;
	e[tot].to=v;
	e[tot].dis=w;
}
inline bool cmp(edge a1,edge a2)
{
	return a1.dis<a2.dis;
}
inline int find(int x)
{
	if(x==fa[x]) return fa[x];
	else return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
	x=find(x),y=find(y);
	fa[x]=y;
}
inline void solve1()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	}
	sort(e+1,e+m+1,cmp);
	int l=0,u,v;
	while(cnt<n-1)
	{
		++l,u=e[l].from,v=e[l].to;		
		if(find(u)!=find(v))
			ans+=e[l].dis,merge(u,v),++cnt;
	}
	cout<<ans;
}
inline void solve2()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int res=0x7fffffffffffffff;
			for(int l=1;l<=k;l++)
				res=min(d[l][i]+d[l][j],res);
			add(i,j,res);
		}
	sort(e+1,e+tot+1,cmp);
	int l=0,u,v;
	while(cnt<n-1)
	{
		++l,u=e[l].from,v=e[l].to;		
		if(find(u)!=find(v))
			ans+=e[l].dis,merge(u,v),++cnt;
	}
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m>>k;
	if(k==0)
		solve1();
	else
		solve2();
}
