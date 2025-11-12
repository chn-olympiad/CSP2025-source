/*

拜谢 DWOI！！！！！！

记 d_i 表示人 i 最晚什么时候可能被录用。

则相当于给每个人分配一个时间 t_i（s_{t_i} = 1），求 t_i <= d_i 个数 >= m 的方案数。

设这样的 t 有 c 个。 

把它们拍到一个序列上从小到大排。

dp[i][j][k] 表示前 i 个点，匹配 j 对，成功 k 对的方案数。

t : dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] * (可匹配的 d 个数)；

d : dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - 1] * (可匹配的 t 个数)；

答案即为 dp[c + n][c][m] * (n - c)!

update : 他妈的怎么还要算放弃的人啊 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, m, s[502], d[502], c, dp[2][502][502], sd[1002], st[1002], ans;
char op;
struct node {
	ll x, op;
	bool operator < (const node bz) const {
		return x < bz.x || (x == bz.x && op < bz.op);
	}
}a[1002];
ll qmi(ll x, ll y) {
	ll res = 1;
	while (y) res = (res * (y & 1 ? x : 1)) % mod, y >>= 1, x = x * x % mod;
	return res; 
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++ ) cin >> op, s[i] = s[i - 1] + ('1' - op);
	if (s[n] == 0) {
		for (ll i = 1, x; i <= n; i ++ ) cin >> d[i], c += (d[i] != 0);
		ll len = 0;
		for (ll i = 1; i <= n; i ++ ) if (d[i]) d[++ len] = d[i];
		sort(d + 1, d + len + 1);
		dp[0][0][0] = 1;
		d[0] = 1;
		for (ll i = 1; i <= c; i ++ ) cout << d[i] << " ";
		cout << "\n";
		for (ll i = 1; i <= c; i ++ ) for (ll j = 0; j < d[i] && j <= n - c; j ++ ) for (ll k = 0; k <= j; k ++ ) (dp[0][i][j] += dp[0][i - 1][k]) %= mod;
		ll ans = 0;
		for (ll i = 0; i <= n; i ++ ) ans = (ans + dp[0][c][i]) % mod;
		cout << (c >= m ? ans : 0) << "\n";
		return 0;
	}
	s[n + 1] = 114514;
	for (ll i = 1, x; i <= n; i ++ ) {
		cin >> x;
		d[i] = 1;
		while (d[i] <= n && s[d[i]] < x) d[i] ++; d[i] --;
		cout << i << ": " << d[i] << "\n";
		a[++ c] = {d[i], 1};
	}	
	for (ll i = 1; i <= n; i ++ ) if (s[i] == s[i - 1]) a[++ c] = {i, 0};
	sort(a + 1, a + c + 1);
	dp[0][0][0] = 1;
	for (ll i = 1; i <= c; i ++ ) {
		if (a[i].op == 0) st[i] ++;
		else sd[i] ++;
		st[i] += st[i - 1], sd[i] += sd[i - 1];
		cout << i << ": " << a[i].x << " " << (a[i].op ? "d" : "t") << ", " << st[i] << " " << sd[i] << "\n";
	}
	for (ll i = 1; i <= c; i ++ ) for (ll j = 0; j <= n; j ++ ) for (ll k = 0; k <= n; k ++ ) {
		if (a[i].op == 0) {
			dp[i & 1][j][k] = dp[(i - 1) & 1][j][k];
			if (j) dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[(i - 1) & 1][j - 1][k] * max(0ll, (sd[i - 1] - j + 1)) % mod) % mod;
		}
		if (a[i].op == 1) {
			dp[i & 1][j][k] = dp[(i - 1) & 1][j][k];
			if (j && k) dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[(i - 1) & 1][j - 1][k - 1] * max(0ll, (st[i - 1] - j + 1)) % mod) % mod;
		}
//		cout << i << " " << j << " " << k << ": " << dp[i & 1][j][k] << "\n";
	}
	for (ll i = m; i <= c - n; i ++ ) /*cout << i << ": " << dp[n & 1][c - n][i] << "\n", */ans = (ans + dp[n & 1][c - n][i]) % mod;
	for (ll i = 1; i <= 2 * n - c; i ++ ) ans = ans * i % mod;
	cout << ans;
}
/*
5 2
10010
0 1 1 2 3
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
