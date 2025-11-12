#include <bits/stdc++.h>
using namespace std;
int n, m, r, a[200], t[12][12];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) cin >> a[i];
	r = a[0], sort(a, a + n * m, greater<int>());
	for (int i = 0; i < n * m; i++)
		if ((i / n + 1) & 1) t[i / n + 1][i % n + 1] = a[i];
		else t[i / n + 1][n - i % n] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (t[i][j] == r) return cout << i << ' ' << j, 0;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
