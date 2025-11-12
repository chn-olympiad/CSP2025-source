// Become Nailoong
#include <bits/stdc++.h>
#define int long long
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x); fout(x);
using namespace std;
constexpr int mod = 998244353;
int n, m;
string s;
bool Allone = true;

namespace Sub1 {
	
constexpr int N = 5e2 + 5;
int a[N], dp[N], tmp[N], ans;
void solve() {
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1), dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (a[i + 1] <= j) tmp[j] = (tmp[j] + dp[j] * (i - j + a[i + 1])) % mod, tmp[j + 1] = (tmp[j + 1] + dp[j] * (j - a[i + 1] + 1)) % mod;
			else tmp[j] = (tmp[j] + dp[j] * (i + 1)) % mod;
		}
		for (int j = 0; j <= i + 1; ++j) dp[j] = tmp[j], tmp[j] = 0;
	}
	for (int i = n - m; ~i; --i) ans = (ans + dp[i]) % mod;
	cout << ans;
}
	
}

namespace Sub2 {
	
constexpr int N = 5e2 + 5;
int buc[N], now, sum, ans = 1, tot = 1;
vector <int> v;
void solve() {
	for (int i = 1, x; i <= n; ++i) cin >> x, ++buc[x], tot = tot * i % mod;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '0') v.push_back(n);
		else v.push_back(i);
	}
	sort(v.begin(), v.end());
	for (int i : v) {
		while(now <= i) sum += buc[now], ++now;
		ans = ans * sum % mod, --sum;
	}
	cout << (tot - ans + mod) % mod;
}


}

namespace Sub3{
	
constexpr int N = 20;
constexpr int M = 3e5 + 5;
int a[N], dp[M][N], pop[M], ans;
void solve() {
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < (1 << n); ++i) pop[i] = pop[i ^ (i & (-i))] + 1;
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n) - 1; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (!((i >> k) & 1)) {
		int nj = j + (a[k] <= j || s[pop[i]] == '0');
		dp[i ^ (1 << k)][nj] = (dp[i ^ (1 << k)][nj] + dp[i][j]) % mod;
	}
	for (int i = n - m; ~i; --i) ans = (ans + dp[(1 << n) - 1][i]) % mod;
	cout << ans;
}

}

signed main() {
	file(employ);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> s;
	for (auto i : s) if (i != '1') Allone = false;
	if (n == m && !Allone) return (cout << 0), 0;
	if (Allone) Sub1::solve();
	else if (m == 1) Sub2::solve();
	else Sub2::solve();
}
