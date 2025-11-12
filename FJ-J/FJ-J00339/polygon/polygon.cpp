#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
const int N = 1e4 + 10;
int n, a[N], cnt[N], pre[N];
ll f[N], sum[N], ans;
ll qpow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	int Max = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], Max = max(Max, a[i]), cnt[a[i]]++;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = Max; j >= a[i]; j--) f[j] = (f[j] + f[j - a[i]]) % mod;
	sum[0] = 0, pre[0] = 0;
	for (int i = 1; i <= Max; i++) sum[i] = (sum[i - 1] + f[i]), pre[i] = pre[i - 1] + cnt[i];
	for (int i = 1; i <= Max; i++) {
		if (!cnt[i]) continue;
		ll t = qpow(2, pre[i - 1]) - 1;
		ll res1 = 1ll * (t + 1) * (qpow(2, cnt[i]) - cnt[i] - (cnt[i] - 1) * cnt[i] / 2 - 1) % mod;
		ll res2 = 1ll * ((cnt[i] - 1) * cnt[i] / 2) * t % mod;
		ll res3 = 1ll * cnt[i] * (t - sum[i] + cnt[i]) % mod;
		ans = (((ans + res1) % mod + res2) % mod + res3) % mod;
	}
	cout << (ans % mod + mod) % mod << "\n";
	return 0;
}

