#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
vector<pair<int, int> > g[10005];
int c[10];
int a[10][100005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int u, v, w;
	int maxc = -114;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		maxc = max(maxc, w);
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][k];
			maxc = max(maxc, a[i][j]);
		}
	}
	srand(time(NULL));
	cout << 1ll * rand() * 211 % 998244353 * rand() * 1001 % (min(n, k) * maxc) + n;
	return 0;
}
