#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[15][10005];
int c[15];
int father[10005];
struct edge
{
	int u, v, w;
}r[10005];

int find(int x)
{
	if (father[x] != x)
	{
		father[x] = find(father[x]);
	}
	return father[x];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	return 0;
}
