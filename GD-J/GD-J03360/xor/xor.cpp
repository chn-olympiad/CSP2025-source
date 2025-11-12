#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
ll n, k, a[maxn], s[maxn], f[maxn], g[1 << 21], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i < (1 << 21); i++) g[i] = -1e18;
	g[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = max(g[s[i] ^ k] + 1, f[i - 1]);
		g[s[i]] = max(g[s[i]], f[i]);
		ans = max(ans, f[i]);
	}
	cout << ans << '\n';
	return 0;
} 
