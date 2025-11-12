#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, j, k) for (int i = j; i <= k; ++i)
int n, m;
const int mod = 998244353;
int s[505], c[505], f[505], id[505];
bool vis[505];
int ans = 0;
void dfs(int i) {
	if (i == n + 1) {
		int nc = 0;
		rep (j, 1, n) {
			if (s[j] == 0 || c[f[j]] <= nc) nc++;
		}
	//	cout << n - nc << '\n';
		ans += (n - nc >= m);
		return ;
	}
	rep (j, 1, n) {
		if (!vis[j]) {
			vis[j] = 1;
			f[i] = j;
			dfs(i + 1);
			vis[j] = 0;
		}
	}
}
mt19937_64 rnd(time(0));
signed main() {
	srand(time(0));
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int su = 0, res = 0;
	cin >> n >> m;
	rep (i, 1, n) {
		char ch;
		cin >> ch;
		s[i] = ch - '0';
		su += s[i];
	}
	rep (i, 1, n) cin >> c[i], res += c[i] == 0;
	if (n <= 20) {
		dfs(1);
		cout << ans << '\n';
	} else if (su == n) {
		long long fac = 1;
		rep (i, 1, n) fac = fac * i % mod;
		cout << fac << '\n';
	} else if (m == n) {
		cout << 0 << '\n';
	} else {
		rep (i, 1, n) id[i] = i;
		double tim = 1e7 / n;
		for (; tim >= 0.0001; tim *= 0.92718) {
			int x = rnd() % n + 1, y = rnd() % n + 1;
			swap(c[x], c[y]);
			int nc = 0;
			rep (j, 1, n) {
				if (s[j] == 0 || c[j] < nc) nc++;
			}
			ans += (n - nc >= m);
			if (n - nc < m && 1.0 * rand() / RAND_MAX >= (tim - 1.0 * rand()) / RAND_MAX / RAND_MAX) swap(c[x], c[y]);
		}
		cout << ans << '\n';
	}
}
