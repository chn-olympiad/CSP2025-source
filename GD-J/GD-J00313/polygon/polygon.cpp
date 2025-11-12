#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
#define csep constexpr

// --------------------------------------------------------------------------------------------

bool mem1;
csep i32 MAXN = 5005, L = 10001, mod = 998244353;
i32 n, a[MAXN], dp[MAXN][MAXN << 1], ps[MAXN][MAXN << 1], ans;
bool mem2;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (i32 i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0] = ps[0][0] = 1;
	for (i32 i = 1; i <= n; ++i) {
		// dp[i][s]
		for (i32 s = a[i]; s < L; ++s)
			dp[i][s] = ps[i - 1][s - a[i]];
		// dp[i][L]
		for (i32 s1 = L - a[i]; s1 <= L; ++s1) {
			dp[i][L] += ps[i - 1][s1];
			if (dp[i][L] >= mod)
				dp[i][L] -= mod;
		}
		// pre
		for (i32 s = 0; s <= L; ++s) {
			ps[i][s] = ps[i - 1][s] + dp[i][s];
			if (ps[i][s] >= mod)
				ps[i][s] -= mod;
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 s = 0; s <= L; ++s) {
			if (s > (a[i] << 1)) {
				ans += dp[i][s];
				if (ans >= mod)
					ans -= mod;
			}
		}
	}
	cout << ans << endl;
	fflush(stdout);
	return 0;
}

/*

For international readers: goto line 79.

吉吉国第一次数学危机：木棍+木棍=木棍。自那以后人们改用绳结记事。 

m\ge3 的条件是没用的。将 a 排序。 

设 \mathrm{dp}_{i,s} 表示最后选的是第 i 个棍木，选了的棍木的长度和为 s 的方案数。则 \mathrm{dp}_{i,s}=\sum_{j=0}^{i-1}\mathrm{dp}_{j,s-a_i}。

用前缀和优化，设 \mathrm{pre}_{i,s}\coloneqq\sum_{j=0}^i\mathrm{dp}_{i,s}，则有 \mathrm{dp}_{i,s}=\mathrm{pre}_{i-1,s-a_i}。这样的复杂度是 O(nV^2)。

最终答案为 \sum_{i=1}^n\sum_{s=0}^{+\infty}[s>2a_i]\mathrm{dp}_{i,s}。

发现我们只关心 [s>2a_i]。于是令 L\coloneqq2V+1，定义 \mathrm{dp}_{i,L} 为棍木长度和 \ge L 的方案数。那么转移变成

\mathrm{dp}_{i,s}=
\begin{cases}
\mathrm{pre}_{i-1,s-a_i},&s<L\\
\sum_{s'=s-a_i}^s\mathrm{pre}_{i-1,s'},&S=L
\end{cases} 

变成 O(nV)。懒得写滚木数组了，反正只用了 400MB。

手造大数据在linux下用1.2s，windows用0.2s。 

First Math Axiom of Otto Country: stick+stick=stiottomomck=stick. From then on all of them use __gnu_pbds::rope.

m\ge3 is useless. sort a.

Let \mathrm{dp}_{i,s} be the count of choosing of i-th ottomom is the last chosen and all chosen ottomoms sum up to s. \mathrm{dp}_{i,s}=\sum_{j=0}^{i-1}\mathrm{dp}_{j,s-a_i}.

Use prefix sum. Let \mathrm{pre}_{i,s}\coloneqq\sum_{j=0}^i\mathrm{dp}_{i,s} then \mathrm{dp}_{i,s}=\mathrm{pre}_{i-1,s-a_i}. Now we have a O(nV^2) method.

The answer is \sum_{i=1}^n\sum_{s=0}^{+\infty}[s>2a_i]\mathrm{dp}_{i,s}.

One can find out that we only care about [s>2a_i]. So let L\coloneqq2V+1 and redefine \mathrm{dp}_{i,L} to be the count that ottomoms sum up to \ge L. Thus

\mathrm{dp}_{i,s}=
\begin{cases}
\mathrm{pre}_{i-1,s-a_i},&s<L\\
\sum_{s'=s-a_i}^s\mathrm{pre}_{i-1,s'},&S=L
\end{cases} 

Now it's O(nV). Rolling array isn't required, memory usage without it is only 400MB.

Handmake input data used 1.2s on linux but 0.2s on windows.

*/ 
