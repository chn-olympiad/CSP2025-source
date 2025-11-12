#include <bits/stdc++.h>
using namespace std;

int n, m, k, u, v, w, x, ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> u >> v >> w;
		ans += w;
	}
	while (k--) {
		for (int i = 1; i <= n + 1; i++) cin >> x;
	}
	cout << ans;
	return 0;
}
