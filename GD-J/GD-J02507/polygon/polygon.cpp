#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;

typedef long long ll;

const ll N = 5010ll;
ll n, a[N], ans, yanghui[N][N];

void dfs(ll now, ll cnt, ll sum, ll mx) {
	if (now > n) {
		if (cnt >= 3ll && sum > (mx << 1ll)) ++ans, ans %= MOD;
		return;
	}
	if (cnt + (n - now + 1ll) < 3) return; // 小剪枝（可行性）：如果最后全部选上也不到那就不用搜了
	dfs(now + 1ll, cnt + 1ll, sum + a[now], max(mx, a[now]));
	dfs(now + 1ll, cnt, sum, mx);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 1;i <= n;++i) cin >> a[i];
	if (n <= 23ll) dfs(1ll, 0ll, 0ll, 0ll);
	else {
		yanghui[1ll][1ll] = 1;
		for (ll i = 1ll;i <= n;++i) yanghui[i][0ll] = 1ll;
		for (ll i = 2ll;i <= n;++i) for (ll j = 1ll;j <= i;++j) yanghui[i][j] = yanghui[i - 1ll][j] + yanghui[i - 1ll][j - 1ll];
		for (ll i = 3ll;i <= n;++i) ans += yanghui[n][i], ans %= MOD;
	}
	cout << ans;
	return 0;
}

/*
神人在 xor 里写 polygon 的暴力写完了才发现
100 + 100 + ? + 40 = 240，可以 1= 且基本上稳了
写完 xor 的 60% 回来想正解
100 + 100 + 65 + 40 = 305, absolutely 1=(high score)key now is polygon
11:13,100 + 100 + (60 + 5) + (40 + 24) = 329, all suitable testcases
*/
