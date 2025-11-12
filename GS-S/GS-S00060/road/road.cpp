#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m, k, cost[15], neew[15][10005], fa[10005], ans;
vector<ll> ee[1000005];
bool vis[10005];

struct Node
{
	ll u;
	ll v;
	ll w;
};
Node e[1000005];

bool Cmp(Node x, Node y)
{
	return x.w < y.w;
}

int find(int x)
{
	if (fa[x] == x)
	{
		return x;
	}
	else
	{
		return fa[x] = find(fa[x]);
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> cost[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> neew[i][j];
		}
	}
	ll flag = m;
	for (int z = 1; z <= k; z++)
	{
		for (int i = 1; i <= n; i++)
		{
			flag++;
			e[flag].u = n + z;
			e[flag].v = i;
			e[flag].w = neew[k][i];
		}
	}
	sort(e + 1, e + 1 + flag, Cmp);
	ll check = 0;
	for (int i = 1; i <= flag; i++)
	{
		if (check == n)
		{
			break;
		}
		int fx = find(e[i].u);
		int fy = find(e[i].v);
		if (fx != fy)
		{
			fa[fx] = fy;
			ans += e[i].w;
			if (!vis[e[i].u] && e[i].u <= n)
			{
				vis[e[i].u] = 1;
				check++;
			}
			if (!vis[e[i].v] && e[i].v <= n)
			{
				vis[e[i].v] = 1;
				check++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
