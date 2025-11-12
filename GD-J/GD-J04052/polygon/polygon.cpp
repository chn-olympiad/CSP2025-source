#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
int n;
int a[maxn]; 
// 暴力 
vector<int> v[maxn];
void dfs(int now, int nm, int chos) {
	if (now > n) return ;
	dfs(now + 1, nm + a[now], chos + 1);
	if (chos + 1 >= 3) {
		v[now].push_back(nm + a[now]);
	}
	dfs(now + 1, nm, chos);
}
void solve1() {
	ll ans = 0;
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
		int j;
		if (!v[i].size()) continue;
		if (v[i][v[i].size() - 1] <= 2 * a[i]) continue;
		for (j = 0; j < v[i].size(); j++) {
			if (v[i][j] > 2 * a[i]) break;
		}
		ans += v[i].size() - j;
		ans %= mod;
	}
	cout << ans << endl;
}
// 枚举每一个最大值
// 看前 i 个有多少种方案可以凑成
// 特殊A <= 1 :只要有就行 
ll ksm(ll x, ll k) {
	if (k == 0) return 1;
	if (k == 1) return x;
	ll t = ksm(x, k >> 1);
	if (k & 1) return t * t % mod * x % mod;
	return t * t % mod;
}
void solve() {
	ll ans = 1;
	ans = ksm(2, n);
	ans--;
	ll t = n;
	ans -= n;
	if (n & 1) {
		ans -= ((t - 1) >> 1) % mod * t % mod;
	}
	else 
		ans -= (t >> 1) % mod * (t - 1) % mod;
	cout << (ans + mod) % mod << endl;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (n <= 20) {
		solve1();	
	}
	else {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
