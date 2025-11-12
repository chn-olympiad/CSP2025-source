#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int N = 1e4 + 3;
int n, m, k;
int g[N][N];
bool s[N];
long long ans;

int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	int u, v, w;
	for (int i = 1; i <= m; i ++)
	{
		scanf ("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	int x, s[N];
	for (int i = 1; i <= k; i ++)
	{
		scanf ("%d", &x);
		for (int ii = 1; ii <= n; ii ++) scanf ("%d", &s[ii]);
		for (int ii = 1; ii < n; ii ++)
			for (int iii = ii + 1; iii <= n; iii ++)
				g[u][v] = g[v][u] = min (x + s[ii] + s[iii], g[u][v]);
	}
	queue <int> q;
	q.push (1);
	while (! q.empty ())
	{
		u = q.top ();
		q.pop ();
		long long mina = 4e9;
		int t;
		for (v = 1; v <= n; v ++)
		{
			if (s[v]) continue;
			if (g[u][v] < mina) g[u][v] = mina, t = v;
		}
		q.push (t);
		ans += mina;
	}
	cout << ans;
	return 0;
}

