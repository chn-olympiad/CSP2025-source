#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define rep(i, a, b) for(ll i = (a); i <= (b); i++)
const ll N = 5000 + 10, MOD = 998244353;
ll n, arr[N], cnt = 0;
inline void dfs(ll u, ll sum, ll maxn, ll step) {
	if(step >= 3) {
		if(sum > maxn * 2) {
			cnt = (cnt + 1) % MOD;
		}
	}
	if(step == n) return;
	rep(i, u + 1, n) {
		dfs(i, sum + arr[i], max(maxn, arr[i]), step + 1);
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	rep(i, 1, n) cin >> arr[i];
	if(n < 3) {
		cout << 0;
		return 0;
	}
	sort(arr + 1, arr + 1 + n);
	dfs(0, 0, 0, 0);
	cout << cnt;
	return 0;
}
