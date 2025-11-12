#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, x,s = 0;
	cin >> n >> m >> k;
	int a[10001], b[n + 1], c[10001];
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		a[i] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> x;
		c[i] = x;
		for (int j = 1; j <= n; j++) {
			cin >> b[j];
		}
		sort(c, c + k);
		s += c[0];
		sort(b, b + n);
		for (int i = 0; i < n / 2; i++) {
			s += a[i];
		}
	}
	sort(a, a + m);
	for (int i = 0; i < n / 2; i++) {
		s += a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n / 2; i++) {
		s += a[i];
	}
	cout << s;
	return 0;
}
