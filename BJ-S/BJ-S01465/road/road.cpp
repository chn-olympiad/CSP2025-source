#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, pair<int, int> >, 
		vector<pair<int, pair<int, int> > >, 
	   greater<pair<int, pair<int, int> > > >q;
vector<int> gv[10010];
int gn[10010];
vector<int> gw[10010];
int c[20];
int a[20][10010];
int vis[10010];
int b[20];
long long ans=1e9;
int n, m, k;
int dfs(int pos, long long add)
{
	if (pos>k)
	{
		while (!q.empty())
		{
			q.pop();
		}
		memset(vis, 0, sizeof(vis));
		vis[1]=1;
		for (int i=0;i<gn[1];i++)
		{
			q.push({gw[1][i], {1, gv[1][i]}});
		}
		for (int i=1;i<=k;i++)
		{
			if (b[i])
			{
				if (vis[i+n]==0)
				{
					q.push({a[i][1], {1, i+n}});
				}
			}
		}
		long long anss=0;
		for (int i=1;i<n;i++)
		{
			pair<int, pair<int, int> > x=q.top();
			q.pop();
			int w=x.first;
			pair<int, int> y=x.second;
			int v=y.second;
			if (vis[v]==1)
			{
				i--;
				continue;
			}
			vis[v]=1;
			anss+=w;
			//cout<<y.first<<' '<<v<<' '<<w<<endl;
			if (v>n)
			{
				i--;
			}
			for (int i=0;i<gn[v];i++)
			{
				//cout<<gv[v][i]<<endl;
				if (vis[gv[v][i]]==0)
				{
					q.push({gw[v][i], {v, gv[v][i]}});
				}
			}
			for (int i=1;i<=k;i++)
			{
				if (b[i])
				{
					if (v==i+n)
					{
						for (int j=1;j<=n;j++)
						{
							if (vis[j]==0)
							{
								q.push({a[i][j], {v, j}});
							}
						}
					}
					else
					{
						if (vis[i+n]==0)
						{
							q.push({a[i][v], {v, i+n}});
						}
					}
				}
			}
		}
		//for (int i=1;i<=k;i++)
		//{
		//	cout<<b[i]<<' ';
		//}
		//cout<<':'<<anss<<'+'<<add<<endl;
		ans=min(ans, anss+add);
		return 0;
	}
	if (c[pos]!=0)
	{
		b[pos]=0;
		dfs(pos+1, add);
	}
	b[pos]=1;
	dfs(pos+1, add+c[pos]);
	return 0;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		gv[u].push_back(v);
		gw[u].push_back(w);
		gv[v].push_back(u);
		gw[v].push_back(w);
		gn[u]++;
		gn[v]++;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1, 0);
	cout<<ans<<endl;
	return 0;
}
