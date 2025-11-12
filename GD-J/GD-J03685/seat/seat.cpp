#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, tot, a[105], r, at, l, h;
signed main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	tot = n * m;
	for (int i = 1; i <= tot; ++i)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + tot + 1);
	at = tot - (lower_bound(a, a + tot + 1, r) - a) + 1;
		l = at / n;
	if (at % n)
		++l;
	cout << l << ' ';
	if (l % 2) {
		if (at % n == 0)
			cout << n;
		else
			cout << at % n;
	}
	else {
		if (at % n == 0)
			cout << 1;
		else
			cout << n - (at % n) + 1;
	}
	return 0;
}
