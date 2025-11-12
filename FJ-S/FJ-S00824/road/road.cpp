#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,to,w;
}edge[2000010];
int fa[10010],l_edge,n,m,K,c[10010];
void add_edge(int u,int v,int w)
{
	l_edge++;
	edge[l_edge].u=u;
	edge[l_edge].to=v;
	edge[l_edge].w=w;
}
int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	while(K--)
	{
		int C;
		cin>>C;
		for(int i=1;i<=n;i++)cin>>c[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)add_edge(i,j,c[i]+c[j]),add_edge(j,i,c[i]+c[j]);
	}
	sort(edge+1,edge+1+l_edge,cmp);
	int k=0,answer=0;
	for(int i=1;i<=l_edge&&k<n-1;i++)
	{
		int x=find(edge[i].u),y=find(edge[i].to);
		if(x!=y)
		{
			answer+=edge[i].w;
			fa[y]=x;
			k++;
		}
	}
	cout<<answer;
	return 0;
}
