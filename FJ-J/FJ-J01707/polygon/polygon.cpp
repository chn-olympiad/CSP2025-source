#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
我常常追忆过去。
我该在哪里停留？我问我自己。 

思路：化简式子得到，ai < a1 + ... + ai-1 + ai+1 + ... + an
即枚举i，求在除了i外的区间内找满足和>ai的子序列的方案数ansi，答案为sigma(ansi)
对于ansi，考虑dp：

dpi表示在除i外区间内（下称区间）前i项的>ai的子序列方案数

不选i dpi = dp(i-1)
选i，考虑新增i后区间变化，这部分答案转化为求在1~i-1中找所有使得和<prei（前缀和）-k的子序列方案数。

止步于此，不会写了，遂写暴力qwq。

-- 11:58 
*/

const int N = 505, MOD = 998244353;
int a[N], n, tot;

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i < (1ll << n); i ++) {
		if (__builtin_popcount(i) < 3) continue;
		int res = 0, m = 0;
		for (int j = 0; j < n; j ++) {
			int idx = j + 1;
			if ((i >> j) & 1) res += a[idx], m = max(m,a[idx]);
		}
		if (res > 2 * m) tot ++;
	}
	cout << tot; 
}

signed main () { // TAT yellow<=t4<=green 想不出O n^2，11:44 打完暴力，要 AFO 了（ 
//	freopen ("polygon3.in", "r", stdin);
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	solve ();

	return 0;
}

