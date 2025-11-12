#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 1, x; i < n * m; i++) {
		cin >> x;
		if (x > k)
			cnt++;
	}
	k = cnt / n;
	cout << k + 1 << ' ';
	if (k & 1)
		cout << n - cnt % n;
	else
		cout << cnt % n + 1;
}