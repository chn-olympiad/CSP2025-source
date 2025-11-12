#include<bits/stdc++.h>
using namespace std;

struct nd{
	int v;
	int w;
	int f;
};
vector<nd>a[10005];
int c[15][10005];
queue<int>q;
int vis[10005][10005];
int n,m,k;
long long ans=0;
void bfs(int i)
{
	q.push(i);
	int f[10005];
	for(int i=1;i<=n;i++)
	{
		f[i]=INT_MAX;
	}
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(auto e:a[p])
		{
			if(!vis[p][e.v])
			{
				f[e.v]=min(e.w,f[e.v]);
				vis[p][e.v]=1;
				vis[e.v][p]=1;
				q.push(e.v);
			}
		}
	}
	for(int j=i+1;j<=n;j++)
	{
		ans+=f[j];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w,-1});
		a[v].push_back({u,w,-1});
	}
	int b[100];
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				if(x!=y)
				{
					a[x].push_back({y,b[i]+c[i][x]+c[i][y],-1});
					a[y].push_back({x,b[i]+c[i][x]+c[i][y],-1});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=1;j<=n;j++)
		{
			for(int x=j+1;x<=n;x++)
			{
				vis[j][x]=0;
				vis[x][j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
