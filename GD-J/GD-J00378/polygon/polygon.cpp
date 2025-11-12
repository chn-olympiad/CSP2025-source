#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 5e3 + 5, V = 5000, mod = 998244353;
int n, a[N], pw[N], f[N][N], s[N], ans;

inline int add_mod(int x) {
	return x >= mod ? x - mod : x;
}

inline int sub_mod(int x) {
	return x < 0 ? x + mod : x;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) pw[i] = add_mod(pw[i - 1] << 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= V; ++j) {
			f[i][j] = f[i - 1][j];
			if (j - a[i] >= 0)
				f[i][j] = add_mod(f[i][j] + f[i - 1][j - a[i]]);
		}
	for (int i = 3; i <= n; ++i) {
		s[0] = f[i - 1][0];
		for (int j = 1; j <= V; ++j)
			s[j] = add_mod(s[j - 1] + f[i - 1][j]);
//		cout << pw[i - 1] - s[a[i]] << '\n';
		ans = add_mod(ans + sub_mod(pw[i - 1] - s[a[i]]));
	}
	cout << ans;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/
