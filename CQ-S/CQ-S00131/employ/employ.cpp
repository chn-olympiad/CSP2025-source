#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PII pair<int, int>
#define pc __builtin_popcount
using namespace std;
const int N = 500;
const LL mod = 998244353;
int n, m, c[N + 5]; LL ans = 0;
bool vis[N + 5];
string s;
void dfs(int u = 1, int cnt = 0) {
	if (u == n + 1) {
		ans += (cnt >= m); ans %= mod;
		return;
	}
	int no = u - 1 - cnt;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		vis[i] = 1;
		if (s[u] == '0' || no >= c[i]) dfs(u + 1, cnt);
		else dfs(u + 1, cnt + 1);
		vis[i] = 0;
	}
}
int lowbit(int i) { return i & -i; }
inline void solve() {
	cin >> n >> m;
	cin >> s; s = ' ' + s; int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i]; cnt1 += (c[i] > 0);
	}
	if (cnt1 < m) {
		cout << "0\n";
		return;
	}
	cnt1 = 0;
	for (int i = 1; i <= n; i++) cnt1 += (s[i] == '1');
	if (cnt1 < m) {
		cout << "0\n";
		return;
	}
	if (n <= 10) {
		dfs();
		cout << ans << "\n";
		return;
	}
	if (n <= 18) {
		int p = (1 << n);
		vector<vector<vector<LL> > > dp(2, vector<vector<LL> >(n + 1, vector<LL>(p + 1)));
		vector<int> lg(p + 1); lg[1] = 0;
		for (int i = 2; i <= p; i++) lg[i] = lg[i >> 1] + 1;
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int now = i & 1; int lst = 1 - now;
			for (int j = 0; j <= i; j++) {
				for (int k = 1; k < p; k++) if (pc(k) == i) {
					dp[now][j][k] = 0;
					for (int l = n; l >= 1; --l) if (((k >> (l - 1)) & 1) == 1) {
						int lt = k - (1 << (l - 1));
						if (j && s[i] == '1') dp[now][j][k] += dp[lst][j - 1][lt] * (c[l] > i - j); 
						dp[now][j][k] %= mod;
						dp[now][j][k] += (dp[lst][j][lt] * (c[l] <= i - j - 1 || s[i] == '0')) % mod;
						dp[now][j][k] %= mod;
					}
//					cerr << i << " " << j << " " << k << " " << dp[now][j][k] << "\n";
				}
			}
		}
		ans = 0;
		for (int i = m; i <= n; i++) ans = (ans + dp[n & 1][i][p - 1]) % mod;
		cout << ans << "\n";
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
