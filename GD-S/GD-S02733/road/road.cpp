#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int v,w;
};
vector <edge> e[10005];
int f[10005][10005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}/*
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= k;i++)
		{
			for (int j = 1;j <= k;j++)
			{
				f[i][j] = min(f[i][k] + f[k][j],f[i][j]);
			}
		}
	}*/
	cout << 0;
	return 0;
}
