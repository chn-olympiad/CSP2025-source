//dfs暴力代码        预计50分
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+5;
ll n, k;
ll a[N], s[N];
ll ans;
ll f[N];
void dfs(ll step, ll bg, ll x) {
//	cout << step << " " << bg << " " << x << " " << (s[x]^s[bg - 1]) << '\n';

	if (step <= f[x] && bg == x) {
		return;
	}
	if (bg == x)f[x] = step;

	if (x == n) {
		if ((ll)(s[x]^s[bg - 1]) == k) {
			step++;
		}
		ans = max(ans, step);
		return;
	}
	if ((ll)(s[x]^s[bg - 1]) == k) {
		dfs(step + 1, x + 1, x + 1);
	} else {
		dfs(step, bg, x + 1);
		dfs(step, x + 1, x + 1);
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(f, -1, sizeof f);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	dfs(0, 1, 1);
	cout << ans;
	return 0;
}