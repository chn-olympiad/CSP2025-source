#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5010;
const int mod = 998244353;

int a[N], n, ans;
int c[N][N], jc[N];

inline bool kp (int x, int y) {
	return x > y;
}

inline void dfs (int id, int s, int len, int mx) {
	if (id == n + 1) {
		if (s > 2 && len > mx * 2) {
			ans ++;
//			cout << s << ' ' << len << ' ' << mx << '\n';
		}
		return ;
	}
	dfs (id + 1, s + 1, len + a[id], max (mx, a[id]));
	dfs (id + 1, s, len, mx);
}

inline void Init () {
	jc[0] = 1;
	for (int i = 1; i < N; i ++) jc[i] = jc[i - 1] * i % mod;
	c[1][1] = 1;
	c[2][1] = 2;
	c[2][2] = 1;
	for (int i = 3; i < N; i ++) {
		for (int j = 1; j <= i; j ++) {
			if (i == j) c[i][j] = 1;
			else if (i - 1 == j) c[i][j] = i;
			else c[i][j] = c[i - 1][j] * i / (i - j) % mod;
		}
	}
}

signed main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + 1 + n, kp);
	if (a[1] == 1) {
		Init ();
		int res = 0;
		for (int i = 3; i <= n; i ++) {
			res += c[n][i];
			res %= mod;
		}
		cout << res << '\n';
		return 0;
	}
	dfs (1, 0, 0, 0);
	cout << ans;
	return 0;
}
