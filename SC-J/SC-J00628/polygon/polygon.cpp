#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
constexpr ll MAXN = 5005, mod = 998244353;
ll n, ans, a[MAXN], ny[MAXN];
vector<ll> vec;
inline bool cck() {
	ll tot = 0, mx = 0;
	for (const ll & v : vec) tot += v, mx = max(mx, v);
	return (tot > (mx * 2));
}
inline void dfs(ll now) {
	if (now == n + 1) {
		if (vec.size() >= 3)
			ans += cck();
		return;
	}
	vec.emplace_back(a[now]), dfs(now + 1);
	vec.pop_back(), dfs(now + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	bool ck = 0;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) ck = 1;
	}
	if (!ck) {
		for (ll i = 1; i <= n; ++i) {
			ll cnt = 1;
			while ((cnt * mod + 1) % i != 0) cnt++;
			ny[i] = (cnt * mod + 1) / i;
		}
		ll cnt = 1;
		for (ll i = 1; i <= n; ++i) {
			cnt = cnt * ny[i] % mod * (n - i + 1) % mod;
			if (i >= 3) (ans += cnt) %= mod;
		}
		cout << ans << '\n';
		return 0;
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}