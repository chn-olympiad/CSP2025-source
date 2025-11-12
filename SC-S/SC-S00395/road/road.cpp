#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, k;
int u, v, w;
int c, a;
int ans;
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ans += w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> a;
		}
	}
	cout << ans;
	return 0;
}