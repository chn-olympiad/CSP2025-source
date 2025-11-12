#include<bits/stdc++.h>
using namespace std;
int a[5005][5005];
int vis[5005];
int num;
int n;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w",stdout);
	int m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if(a[u][v] != 0) 
		{
			a[u][v] = min(a[u][v], w);
			a[v][u] = min(a[u][v], w);
		}	
		else
		{
			a[u][v] = w;
			a[v][u] = w;
		}
	}
	if(k == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				if(a[i][j] != 0)
				{
					num += a[i][j];
				}
			}
		}
		cout << num;
	}
	return 0;
}
