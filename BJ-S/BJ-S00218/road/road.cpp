
#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
int a[3000][3000],b[3000][3000];
bool vis[10000];
void dfs(int i,int u,int w)
{
	vis[u]=1;
	b[i][u]=min(w,b[i][u]);
	for(int v=1;v<=n;v++)
	{
		if(vis[v])continue;
		dfs(i,v,w+a[u][v]);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[j]=0;
			b[i][j]=INT_MAX;
		}
		dfs(i,i,0);
	}
	return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s+=b[i][j];
		}
	}
	cout<<s/3;
}

