#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
const int N = 1e5 + 10;
int T, n, a[N], b[N], c[N], d[N];
int max(int x, int y, int z) {
	return max(max(x, y), z);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while (T --) {
		cin >> n;
		rep(i, 1, n) {
			cin >> a[i] >> b[i] >> c[i];
		}
		int sa = 0, sb = 0, sc = 0, sum = 0;
		rep(i, 1, n) {
			int maxs = max(a[i], b[i], c[i]);
			sum += maxs;
			if (maxs == a[i]) ++ sa;
			else if (maxs == b[i]) ++ sb;
			else ++ sc;
		}
		if (sa <= n / 2 && sb <= n / 2 && sc <= n / 2) {
			cout << sum << '\n';
			continue;
		}
		sum = 0;
		if (sa > n / 2) {
			rep(i, 1, n) sum += a[i], d[i] = max(b[i], c[i]) - a[i];
		} else if (sb > n / 2) {
			rep(i, 1, n) sum += b[i], d[i] = max(a[i], c[i]) - b[i];
		} else {
			rep(i, 1, n) sum += c[i], d[i] = max(a[i], b[i]) - c[i];
		}
		sort(d + 1, d + n + 1, greater<int>());
		rep(i, 1, n / 2) {
			sum += d[i];
		}
		cout << sum << "\n";
	}
	return 0;
}
