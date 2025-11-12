#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
#define csep constexpr

// --------------------------------------------------------------------------------------------

csep i32 MAXN = 5e5 + 5;
i32 n, dp[MAXN], mxdpv[2000000];
u32 k, a[MAXN], p[MAXN];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (i32 i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	memset(mxdpv, 0xc0, sizeof mxdpv);
	mxdpv[0] = 0;
	for (i32 i = 1; i <= n; ++i) {
		dp[i] = max(dp[i - 1], 1 + mxdpv[p[i] ^ k]);
		mxdpv[p[i]] = max(mxdpv[p[i]], dp[i]);
	}
	cout << dp[n] << endl;
	fflush(stdout);
	return 0;
}

/*

For international readers: goto line 48.

设 \mathrm{dp}_i 表示最后一段在 i 或之前结尾的最大段数。有暴力转移：

\mathrm{dp}_i=\max(\mathrm{dp}_{i-1},1+\max_{\red{\mathrm{xor}_{l=j+1}^ia_l=k}}\mathrm{dp}_j)

标红的那一段可以前缀和优化。设 p_i\coloneqq\mathrm{xor}_{j=1}^ia_j，则式子变成 \max(\mathrm{dp}_{i-1},1+\max_{p_i\mathbin{p_i\mathrm{xor}}p_j=k}\mathrm{dp}_j)。

再推变成 \max(\mathrm{dp}_{i-1},1+\max_{p_i\mathbin{p_j=p_i\mathrm{xor}}k}\mathrm{dp}_j)。 

所以将每个 p 值对应的 dp 最大值记录即可。O(n)。 

Let \mathrm{dp}_i be the max count of intervals that the last interval ends before or at i. We have:

\mathrm{dp}_i=\max(\mathrm{dp}_{i-1},1+\max_{\red{\mathrm{xor}_{l=j+1}^ia_l=k}}\mathrm{dp}_j)

The red part can be optimized by prefix sum. Let p_i\coloneqq\mathrm{xor}_{j=1}^ia_j then it's \max(\mathrm{dp}_{i-1},1+\max_{p_i\mathbin{p_i\mathrm{xor}}p_j=k}\mathrm{dp}_j).

Thus it equals to \max(\mathrm{dp}_{i-1},1+\max_{p_i\mathbin{p_j=p_i\mathrm{xor}}k}\mathrm{dp}_j).

So memorize max dp value for all p values. O(n).

*/
