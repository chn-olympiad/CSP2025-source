#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
constexpr ll MAXN = 505, mod = 998244353;
ll n, m, ans, c[MAXN];
bitset<MAXN> vis;
str s;
vector<ll> vec;
inline bool cck() {
	ll cnt = 0, suc = 0;
	for (ll i = 0; i < vec.size(); ++i) {
		if (s[i] == '0') cnt++;
		else if (cnt >= c[vec[i]]) cnt++;
		else suc++;
	}
	return suc >= m;
}
inline void dfs() {
	if (vec.size() == n) {
		(ans += cck()) %= mod;
		return;
	}
	for (ll i = 1; i <= n; ++i)
		if (!vis.test(i))
			vis.set(i), vec.emplace_back(i), dfs(), vis.reset(i), vec.pop_back();
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	bool ck = 0;
	ll cnt = 0;
	cin >> n >> m >> s;
	for (const char & c : s)
		if (c == '0') ck = 1;
		else cnt++;
	if (m > cnt) cout << 0 << '\n', exit(0);
	if (n == m && ck) cout << 0 << '\n', exit(0);
	for (ll i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i] == 0 && n == m)
			cout << 0 << '\n', exit(0);
	}
	if (!ck && n >= 15) {
		ans = 1;
		for (ll i = 1; i <= n; ++i)(ans *= i) %= mod;
		cout << ans << '\n';
	}
	dfs();
	cout << ans << '\n';
	return 0;
}