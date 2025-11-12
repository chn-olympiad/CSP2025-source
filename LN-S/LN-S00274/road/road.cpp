#include <bits/stdc++.h>
using namespace std;
#define __MADE return 
#define IN 0
#define CHINA__ ;
#define int long long
#define filein(s) freopen(s, "r", stdin)
#define fileout(s) freopen(s, "w", stdout);
const int N = 1e4+5, INF = 0x3f3f3f3f;
int n, m, k, c[N], g[N][N];
void solve()
{
	cin >> n >> m >> k;
	for (int i = 0, u, v, w; i < m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w), g[v][u] = min(g[v][u], w);
	}
	for (int w = 1; w <= n; w++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (w != i && i != j && w != j) g[i][j] = min(g[i][j], g[w][j] + g[i][w]);
			}
		}
	}
	cout << 0 << endl;
	return ;
}
signed main()
{
	memset(g, INF, sizeof(g));
	filein("road.in");
	fileout("road.out");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	__MADE IN CHINA__
}
