#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+4;
const int M=1e6+6;
int n,m,k;
int fa[N],c[N],a[15][N];
ll ans;
struct Edge
{
	int u,v,w;
	bool operator<(Edge o)
	{
		return w<o.w;
	}
}edge[2*M];
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void solve1()
{
	sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(find(u)==find(v))continue;
		fa[find(u)]=find(v);
		ans+=w;
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	if(k==0)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int pos=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(!a[i][j])pos=j;
		}
		for(int j=1;j<=n;j++)
		{
			if(j==pos)continue;
			edge[++m].u=pos;
			edge[m].v=j;
			edge[m].w=a[i][j]+c[i];
		}
	}
	solve1();
	return 0;
}
