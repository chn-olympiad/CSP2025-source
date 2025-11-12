#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
const int N = 5e3 + 10, p = 998244353;
int n, a[N], ans[N][N], pw2[N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	pw2[0] = 1;
	rep(i, 1, N - 1) {
		pw2[i] = pw2[i - 1] * 2 % p;
	}
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	// ans[i][j]: 前 i 个数中有多少种组合的和大于等于 j
	rep(i, 1, n) {
		rep(j, 0, N - 1) {
			ans[i][j] = ans[i - 1][j];
			if (j - a[i] > 0) {
				ans[i][j] = (ans[i][j] + ans[i - 1][j - a[i]]) % p;
			} else {
				ans[i][j] = (ans[i][j] + pw2[i - 1]) % p;
			}
		}
	}
	int cnt = 0;
	rep(i, 1, n) {
		// ? + a[i] > 2 * a[i]
		// =>     ? > a[i]
		cnt = (cnt + ans[i - 1][a[i] + 1]) % p;
	}
	cout << cnt << '\n';
	return 0;
}
