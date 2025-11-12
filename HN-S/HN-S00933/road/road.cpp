#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k,tot,ans,a[10][N],c[15];
struct Edge{
	int u,v,w;
}e[N];
void add_edge(int u,int v,int w)
{
	++tot;
	e[tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int fa[100005];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	fa[x]=y;
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k!=0)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			int w=INT_MAX;
			for(int kk=1;kk<=k;kk++)
				w=min(w,a[kk][i]+a[kk][j]);
			add_edge(i,j,w);m++;
		}
	}
	
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(find(u)==find(v))continue;
			ans+=w;
			merge(u,v);
		}
	
	cout<<ans<<endl;
	return 0;
}
/*
6 6 0
1 2 1
2 3 2
3 4 3
4 5 4
5 6 5
1 6 6
*/

