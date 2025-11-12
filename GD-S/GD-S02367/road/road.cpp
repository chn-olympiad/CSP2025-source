#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	int map[n+1][n+1];
	for(int i = 0;i <= n;++i)
	for(int j = 0;j <= n;++j)
	map[i][j] = 1e9;
	for(int i = 1;i <= n;++i)
	map[i][i] = 0;
	for(int i = 0;i < m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v] = min(map[u][v],w);
		map[v][u] = min(map[v][u],w);
	}
	int w[k][n+1]; 
	for(int i = 0;i < k;++i)
	{
		for(int j = 0;j <= n;++j)
			cin>>w[i][j];
	}long long ans = 0;
	for(int i = 1;i < n;++i)
	{
		int m = 1e9;
		int u = 0,v = 0,r = -1;
		for(int j = 1;j <= n;++j)
		{
			if(i!=j)
			{
				int w1 = 1e9;
				for(int l = 0;l < k;++l)
				{
					int temp = w[l][i]+w[l][j]+w[l][0];
					if(temp!=0&&temp < w1)
					{
						w1 = w[l][i]+w[l][j]+w[l][0];
						r = l;
					}
				}
				if(map[i][j]!=0&&map[i][j] < m)
				{
					m = map[i][j];
					u = i,v = j;
					r = -1;
				}
				if(w1 <= m)
				{
					m = w1;
					u = i,v = j;
				}
			}
		}
		ans+=m;
		if(r!=-1){w[r][0] = 0;w[r][u] = w[r][v] = 0;}
		map[u][v] = map[v][u] = 0;
	}cout<<ans;
	
}
