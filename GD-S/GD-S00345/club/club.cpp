#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 1e5 + 5;
int t, n, id[N], cnt[4], delta[N], tot, b[N];
ll res;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		res = 0;
		for (int i = 1, a[4]; i <= n; ++i) {
			cin >> a[1] >> a[2] >> a[3];
			int id = 0;
			if (a[1] >= max(a[2], a[3])) {
				id = 1;
				delta[i] = a[1] - max(a[2], a[3]);
			} else if (a[2] >= max(a[1], a[3])) {
				id = 2;
				delta[i] = a[2] - max(a[1], a[3]);
			} else {
				id = 3;
				delta[i] = a[3] - max(a[1], a[2]);
			}
			::id[i] = id;
			++cnt[id];
			res += a[id];
		}
		int mx = max({ cnt[1], cnt[2], cnt[3] });
		if (mx > n / 2) {
			int t = 0, ned = mx - n / 2;
			if (cnt[1] == mx) t = 1;
			else if (cnt[2] == mx) t = 2;
			else t = 3;
			tot = 0;
			for (int i = 1; i <= n; ++i)
				if (id[i] == t)
					b[++tot] = delta[i];
			sort(b + 1, b + tot + 1);
			for (int i = 1; i <= ned; ++i)
				res -= b[i];
		}
		cout << res << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
