#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, mod = 998244353;

struct S {
	int u, v, w;
};

struct node {
	int d, id;
	bool operator < (const node &o) const {
		return d > o.d;
	}
};

vector <S> e[N];

bool vis[N];
int n, m, k, ans = 1e9;

void dfs (int id, int sum, int tot)
{
	if (tot == n)
	{
		ans = min (ans, sum);
		return ;
	}
	for (auto i : e[id])
	{
		int u = i.u, v = i.v, w = i.w;
		if (vis[v])
		{
			continue;
		}
		vis[v] = true;
		dfs (v, sum + w, tot + (v <= n ? 1 : 0));
		vis[v] = false;
	}
}

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back ((S){u, v, w});
		e[v].push_back ((S){v, u, w});
	}
	for (int i = 1; i <= k; i++)
	{
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			e[i + n].push_back ((S){i + n, j, w});
			e[j].push_back ((S){j, i + n, w});
		}
	}
	dfs (1, 0, 1);
	cout << ans;
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
