#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,cnt,ans;
int fa[10001];
int c[11],aij[11][10001];

struct node
{
	int u,v,w;
}edge[2000001];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
}

bool cmp(node a,node b)
{
	return a.w<b.w;
}

void kruskal()
{
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu==fv) continue;
		ans+=edge[i].w;
		fa[fu]=fv;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[++cnt].u=u;
		edge[cnt].v=v;
		edge[cnt].w=w;
		edge[++cnt].u=v;
		edge[cnt].v=u;
		edge[cnt].w=w;		
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>aij[i][j];
		}
	}
	kruskal();
	cout<<ans;
	return 0;
}
