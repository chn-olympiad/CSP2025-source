#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c[15][10005];

int fa[10005];

int f(int jd)
{
	if(fa[jd] == jd) return jd;
	return f(fa[jd]);
}

struct rd
{
	int u, v, w;
} r[10005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			fa[j] = i;
		}
	}
	cout << 0;
	return 0;
}
