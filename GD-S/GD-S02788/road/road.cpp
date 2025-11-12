#include<bits/stdc++.h>
using namespace std;
int fa[10015];
int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void unite(int x,int y)
{
	if(find(x) != find(y))
	{
		fa[y] = x;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<pair<int,int> > G[10005];
			for(int i = 1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
		int c[15][10005];
		for(int i = 1;i<=k;i++)
		{
			cin>>c[i][0];
			for(int j = 1;j<=n;j++)
			{
				cin>>c[i][j];
			}
		}
		long long ans = 0;
		for(int i = 1;i<=n;i++)
		{
			fa[i] = i;
		}
		int minn = 0x3f3f3f3f;
		for(auto v : G[1])
		{
			minn = min(minn,v.second);
		}
		for(auto v : G[1])
		{
			if(v.second == minn)
			{
				ans += v.second;
				unite(1,v.first);
				break;
			}
		}
		for(int i = 2;i<=n;i++)
		{
			if(find(1) != find(i))
			{
				int minn = 0x3f3f3f3f;
				for(auto v : G[i])
				{
					if(find(1) == find(v.first))
					{
						minn = min(minn,v.second);
					}
				}
				ans += minn;
				unite(1,i);
				
			}
		}
		cout<<ans<<endl;	
	return 0;
}
