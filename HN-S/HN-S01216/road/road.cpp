#include <bits/stdc++.h>

using namespace std;

int n, m, k;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		sum += w;
	}
	cout << sum;
	return 0;
}

