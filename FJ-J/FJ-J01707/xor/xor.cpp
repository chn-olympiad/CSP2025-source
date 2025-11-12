#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 5e5, V = 2e6;
int pre[N], a[N], n, k, cnt[V], tot, dp[N];
vector<pii> ans;

bool cmp (pii a, pii b) {
	return a.se < b.se;
}

void solve () {
	cin >> n >> k;
	for (int i = 1; i <= V; i ++) cnt[i] = -1;
	for (int i = 1; i <= n; i ++) cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
	for (int i = 1; i <= n; i ++) {
//		if (a[i] == k) ans.push_back ({i, i});
//		cout << i << ' ' << (pre[i] ^ k) << " " << cnt[pre[i] ^ k] << endl; !!! prefect!
		if (cnt[pre[i] ^ k] != -1) ans.push_back ({cnt[pre[i] ^ k] + 1, i});
		cnt[pre[i]] = i;
	}
	sort (ans.begin (), ans.end (), cmp);
	// dp -> max count
	// dp_i -> 前 i 个数能取到的不相交的区间最大值
	// for [l,r] r = i, dp_i = max (dp_i, dp_(l - 1)) + 1
	for (int i = 0; i < ans.size (); i ++) {
		if(ans[i].se != ans[i - 1].se) {
			for (int j = ans[i - 1].se + 1; j <= ans[i].se; j ++) dp[j] = dp[j - 1];
		}
		dp[ans[i].se] = max (dp[ans[i].se], dp[ans[i].fi - 1] + 1);
	}
	int res = 0;
	for (int i = 1; i <= n; i ++) res = max (res, dp[i]);
	cout << res << endl;
	 
//	for (int i = 0; i < ans.size (); i ++) cout << ans[i].fi << ' ' << ans[i].se << endl;
}

signed main () { // 10:12 AC!!! 调了半天发现dp转移方程错了。。。 t3<=yellow 
//	freopen ("xor6.in", "r", stdin);
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	solve ();

	return 0;
}

