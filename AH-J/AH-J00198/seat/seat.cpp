#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
int n, m, a[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	rep(i, 1, n * m) {
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1, a + n * m + 1);
	int p = lower_bound(a + 1, a + n * m + 1, k) - a;
	p = n * m - p + 1;
	int col = (p + n - 1) / n;
	cout << col << ' ';
	int line = p % n;
	if (line == 0) {
		line = n;
	}
	if (col % 2 == 0) {
		line = n - line + 1;
	}
	cout << line << '\n';
	return 0;
}
