#include <bits/stdc++.h>
using namespace std;

int n, m, k, tpa, v[1000005];
long long num = 0x3f;
struct node
{
	int d, f;
}l;
vector <node>q[1000005];

void dfs (int c, int fa, long long mon)
{
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			break;
		}
		if (i == n)
		{
			num = min(num, mon);
			return;
		}
	}
	v[c] = 1;
	for (int i = 0; i < q[c].size(); i++)
	{
		int x = q[c][i].d, h = q[c][i].f;
		if (x == fa)
		{
			continue;
		}
		if (v[x] == 0)
		{
			v[x] = 1;
			dfs(x, c, mon+h);
		}
		v[x] = 0;
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		l.d = u;
		l.f = w;
		q[v].push_back(l);
		l.d = v;
		q[u].push_back(l);
	}
	int c;
	for (int i = 1; i <= k; i++)
	{
		cin >> c;
		if (c != 0)
		{
			tpa = 1;
		}
		int a;
		for (int j = 1; j <= n; j++)
		{
			cin >> a;
			if (a != 0)
			{
				tpa = 1;
			}
		}
	}
	if (k == 0)
	{
		dfs(1, 1, 0);
		cout << num;
	}
	else if (tpa == 0)
	{
		cout << 0;
	}
	return 0;
}
