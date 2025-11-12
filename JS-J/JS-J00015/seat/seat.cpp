#include<bits/stdc++.h>

using namespace std;

int a[105];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) cin >> a[i];
	int shu = a[0];
	sort(a, a + n * m);
	int pos = n * m - (lower_bound(a, a + n * m, shu) - a) - 1;
	cout << pos / n + 1 << ' ' << (pos % (2 * n) < n ? pos % n + 1: n - pos % n);
	return 0;
}