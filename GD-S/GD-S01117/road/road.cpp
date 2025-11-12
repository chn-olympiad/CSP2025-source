#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge
{
	int v,w;
};
int op=1,n,m,k,c[15][N];
vector<edge>e[N];
int f[N];
int find(int x)
{
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++)f[i]=i;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		if(c[i][0])op=0;
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j])op=0;
		}
	}
	if(op)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
