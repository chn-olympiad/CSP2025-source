#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 505, mod = 998244353;
int n, m, c[N], cnt[N], pre[N], po[N], f[N][N];
bool vis[N];
vector<int>v;
char s[N];
int solve(int S)
{
	for (int i = 1; i <= n; ++i) {
		// int o = ((S >> (i - 1)) & 1);
		int o = vis[i];
		if (s[i] == '0' && o) return 0;
		pre[i] = pre[i - 1] + o;
		po[i] = po[i - 1] + (s[i] == '0');
	}
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= pre[i]; ++j) {
			int o = vis[i];
			// int o = ((S >> (i - 1)) & 1);
			if (o) {
				if (j) f[i][j] = (f[i][j] + (ll) f[i - 1][j - 1] * (cnt[i - 1 - pre[i - 1]] - (i - 1) + pre[i - 1] - (j - 1) + po[i - 1])) % mod;
				f[i][j] = (f[i][j] + (ll) f[i - 1][j] * (po[i - 1] + pre[i - 1] - j + 1)) % mod;
			} else {
				if (s[i] == '0') {
					f[i][j] = (ll) f[i - 1][j] * (po[i - 1] + pre[i - 1] - j + 1) % mod;
				} else {
					f[i][j] = (ll) f[i - 1][j] * (cnt[i - 1 - pre[i - 1]] - (i - 1) + pre[i - 1] - j + po[i - 1]) % mod;
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= pre[n]; ++j) {
		ans = (ans + (j & 1 ? -1ll : 1ll) * f[n][j]) % mod;
	}
	return ans;
}
bool en;
int main()
{
	freopen("employ.in", "r", stdin);
#ifdef xu
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n------------------" << endl;
#else
	freopen("employ.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		++cnt[c[i]];
		if (s[i] == '1') v.emplace_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i] += cnt[i - 1];
	}
	int ans = 0;
	for (int S = 0; S < 1 << v.size(); ++S) {
		if (__builtin_popcount(S) >= m) {
			for (int j = 0; j < v.size(); ++j) {
				if ((S >> j) & 1) {
					vis[v[j]] = 1;
				} else {
					vis[v[j]] = 0;
				}
			}
			ans = (ans + solve(S)) % mod;
		}
	}
	cout << (ans + mod) % mod << endl;
	return 0;
}