#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const int N = 10030, M = 2100010;

int n, m, k, num;
LL w[15], d[1030][1030];
int p[N];
struct Edge
{
	int a, b;
	LL w;
	bool operator < (const Edge& W) const
	{
		return w < W.w;
	}
} edges[M];
LL a[15][N];

int find(int x)
{
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

LL kruscal()
{
	LL res = 0LL;
	sort(edges + 1, edges + num + 1);
	for (int i = 1; i <= num; i ++ )
	{
		int u = edges[i].a, v = edges[i].b;
		u = find(u), v = find(v);
		if (u != v)
		{
			p[u] = v;
			res += edges[i].w;
		}
	}
	return res;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> k; num = m;
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		int a, b, w; cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	for (int i = 1; i <= k; i ++ )
	{
		cin >> w[i];
		for (int j = 1; j <= n; j ++ ) 
			cin >> a[i][j];
	}
	
	if (k == 0)
	{
		cout << kruscal() << endl;
		return 0;
	}
	
	LL ans = kruscal();
	for (int s = 1; s < (1 << k); s ++ )
	{
		memset(d, 0x3f, sizeof d);
		for (int i = 1; i <= n; i ++ ) p[i] = i;
		num = m;
		
		LL sum = 0LL;
		for (int i = 1; i <= k; i ++ )
			if ((s >> (i - 1)) & 1)
			{
				sum += w[i];
				for (int u = 1; u <= n; u ++ )
					for (int v = 1; v <= n; v ++ )
						d[u][v] = d[v][u] = min(d[u][v], a[i][u] + a[i][v]);
			}
		for (int u = 1; u <= n; u ++ )
			for (int v = u + 1; v <= n; v ++ )
				if (d[u][v] != (LL)0x3f3f3f3f3f3f3f3f)
					edges[ ++ num ] = {u, v, d[u][v]};
		sum += kruscal();
		ans = min(ans, sum);
	}
	
	cout << ans << endl;

	return 0;
}

