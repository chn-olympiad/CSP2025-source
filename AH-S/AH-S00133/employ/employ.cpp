#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
const int N = 510, P = 998244353;
int n, m, c[N], ans, fac[N], p[N];
bool s[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fac[0] = 1;
	rep(i, 1, N - 1) {
		fac[i] = fac[i - 1] * i % P;
	}
	cin >> n >> m;
	bool is_all_1 = true;
	rep(i, 1, n) {
		char ch;
		cin >> ch;
		s[i] = ch == '1';
		if (!s[i]) {
			is_all_1 = false;
		}
	}
	rep(i, 1, n) {
		cin >> c[i];
	}
	if (is_all_1) {
		cout << fac[n];
		return 0;
	}
	rep(i, 1, n) {
		p[i] = i;
	}
	do {
		int cnt = 0, failed = 0;
		rep(i, 1, n) {
			if (failed >= c[p[i]]) {
				++ failed;
			} else if (s[i]) {
				++ cnt;
			} else {
				++ failed;
			}
		}
		if (cnt >= m) {
			++ ans;
		}
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}
