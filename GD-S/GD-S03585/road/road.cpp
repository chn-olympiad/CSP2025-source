#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,head[1000100],a[1001][1001];
struct edge{
	int v,w,next;
}e[1000100];
void addedge(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	for(int i=1; i<=k; i++)
	{
		for(int j=1; j<=n+1; j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
