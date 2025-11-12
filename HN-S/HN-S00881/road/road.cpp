#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int K=1e1+5;
const int M=1e6+5;
int n,m,k;
int u[M],v[M],w[M];
int c[K];
int vis[K][N];
int m[N][N];
void dfs(x)
{
	for(int i=1;i<=n;i++)
	{
		if(x!=i&&Map[x][i]=-1)
		{	
			s=s+m[x][i];
			dfs(i);
			s=s-m[x][i];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		m[u[i]][v[i]]=w[i];
		Maps[u[i]][v[i]]=-1;
		Maps[v[i]][u[i]]=-1;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>vis[i][j];
		}
	}
	
	return 0;
} 
