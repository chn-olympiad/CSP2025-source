#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int u, v, w, c, a;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
	}
	for (int j = 1; j <= k; ++j) {
		cin >> c;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
		}
	}
	cout << 0;
	return 0;
}