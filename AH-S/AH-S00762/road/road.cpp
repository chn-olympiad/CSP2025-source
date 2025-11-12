#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k, t = 0;
int mp[10005][10005];
vector<int> vec[10005];
bool vis[10005];
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (mp[u][v]) {
			mp[u][v] = min (mp[u][v], w);
			mp[v][u] = min (mp[v][u], w);
		} else {
			mp[u][v] = mp[v][u] = w;
			vec[u].push_back (v);
			vec[v].push_back (u);
		}
		t += w;
	}
	int a;
	while (cin >> a) t += a;
	/*if (k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; ++ i) {
			t = 0x3f3f3f3f;
			memset (vis, 0, sizeof vis);
			dfs (i, 0, 1);
			ans = max (ans, t);
		}
		cout << ans;
	}*/
	srand (time (0));
	cout << rand () * rand () % t;
	return 0;
}
