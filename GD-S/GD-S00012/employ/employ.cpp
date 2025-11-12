#include <bits/stdc++.h>
using namespace std;
const long long N = 505, mod = 998244353;
long long n, m, c[N], tf[N], dp[N], p[N], jc[N];
char s[N];
bool g[N];
namespace ten_point
{
	long long dfs(long long x)
	{
		if (x > n)
		{
			long long cnt = 0;
			for (long long i = 1; i <= n; i++)
				if (s[i] == '1' && tf[i] + cnt >= i)
					cnt++;
			return cnt >= m;
		}
		long long ans = 0;
		for (long long i = 1; i <= n; i++)
		{
			if (!g[i])
			{
				g[i] = true;
				tf[x] = c[i];
				ans += dfs(x + 1);
				g[i] = false;
			}
		}
		return ans;
	}
	void solve()
	{
		memset(tf, 0, sizeof tf);
		memset(g, false, sizeof g);
		printf("%lld", dfs(1));
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s", &n, &m, s + 1);
	for (long long i = 1; i <= n; i++)
		scanf("%lld", c + i);
	sort(c + 1, c + 1 + n);
	if (n <= 10)
	{
		ten_point::solve();
		return 0;
	}
	for (long long i = 1; i <= n; i++)
		p[i] = p[i - 1] + (s[i] == '1');
	jc[1] = jc[0] = 1;
	for (long long i = 2; i <= n; i++)
		jc[i] = (jc[i - 1] * i) % mod;
	dp[0] = 1;
	for (long long i = 1; i <= n; i++)
		for (long long j = p[c[i]]; j > 0; j--)
			(dp[j] += dp[j - 1] * (p[c[i]] - j + 1) % mod) %= mod;
	long long ans = 0;
	for (long long i = m; i <= n; i++)
		(ans += (dp[i] * jc[n - i]) % mod) %= mod;
	printf("%lld", ans);
}
