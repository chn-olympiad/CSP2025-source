#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005, mod = 998244353;
int n, a[N], f[N][N], b[N], cnt[N], pos[N], pw[N], c[N][N];

signed main() {
	freopen("polygon.in", "r", stdin); freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++, pos[a[i]] = i;
    for (int i = 0; i <= n; i++) {
    	c[i][0] = 1;
    	for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    for (int i = (pw[0] = 1); i <= n; i++) pw[i] = (pw[i - 1] * 2) % mod;
    for (int i = 1; i <= n; i++) {
    	int tot = 0, val = a[i] + 1;
    	for (int j = 1; j <= n; j++) if (a[j] < a[i]) b[++tot] = a[j];
    	if (pos[a[i]] == i) {
    		int cc = cnt[a[i]];
    		(ans += c[cc][2] * (pw[tot] - 1) % mod) %= mod;
    		for (int t = 3; t <= cc; t++) (ans += c[cc][t] * pw[tot] % mod) %= mod;
    	}
    	for (int i = 0; i <= tot; i++) for (int j = 0; j <= val; j++) f[i][j] = 0;
    	f[0][0] = 1;
    	for (int i = 0; i < tot; i++) for (int j = 0; j <= val; j++) {
    		(f[i + 1][j] += f[i][j]) %= mod;
    		(f[i + 1][min(j + b[i + 1], val)] += f[i][j]) %= mod;
    	} (ans += f[tot][val]) %= mod;
    } cout << ans;
	return 0;
}