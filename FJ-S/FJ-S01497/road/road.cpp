#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge_b
{
	int u,v,w;
}e[5000005];
//vector<int> g[100005];
int c[15];
int a[15][1000005];
int fa[1000005];
int ans=0,cnt=0;
bool cmp(edge_b a,edge_b b)
{
	return a.w<b.w;
}
int find(int x)
{
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i =1;i<=n+k;i++)
	{
		fa[i]=i;
	} 
	for(int i =1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i =1;i<=k;i++)
	{
		cin>>c[i];
//		e[++m]={1,n+i,c[i]};
		for(int j =1;j<=n;j++)
		{
			cin>>a[i][j];
			e[++m]={n+i,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i =1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v))
		{
//			g[u].push_back(v);
//			g[v].push_back(u);
			fa[find(v)]=find(u);
			ans+=w;
			if(cnt++==n+k-1) break;
		}
	}
	cout<<ans;
	return 0;
}
