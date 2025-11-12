#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::cerr;
using std::min;
using std::max;
using std::swap;
const ll P = 998244353;
const int MAXN = 510;
int n, m;
char s[MAXN];
int c[MAXN];
int cnt;
ll fac[MAXN];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		cnt += (c[i] == 0);
	}
	if (n - cnt < m) {
		cout << 0 << '\n';
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i <= 500; ++i) {
		fac[i] = i * fac[i - 1] % P;
	}
	cout << fac[n];
	return 0;
}