/* expect : 24 pts */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
using namespace std;

const int N = 510, mod = 998244353;
inline void Plus(long long &now, long long add)
{now += add; while(now >= mod) now -= mod;}
inline long long qpow(long long a, long long b)
{
	long long res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return res;
}
long long fac[N], inv[N];
inline long long C(int n, int m) {return fac[n] * inv[m] % mod * inv[n - m] % mod;}
inline long long get(int x) {return ((x & 1) ? (mod - 1) : 1);}
inline void init_math()
{
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= 500; ++i) fac[i] = fac[i - 1] * i % mod;
	inv[500] = qpow(fac[500], mod - 2);
	for(int i = 499; i >= 1; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int n, m, k, w[N], c[N], pr[N], buc[N]; string s;

namespace Sol_I
{
	inline void solve()
	{
		for(int i = 1; i <= n; ++i)
		{
			if(c[i] == 0)
			{
				cout << 0 << '\n';
				return ;
			}
		}
		cout << fac[n] << '\n';
	}
}

namespace Sol_II
{
	long long dp[N], res;
	inline void solve()
	{
		dp[0] = 1;
		for(int i = 1; i <= k; ++i)
			if(pr[(i - 1) + w[i]] > i - 1)
				dp[i] = dp[i - 1] * (pr[(i - 1) + w[i]] - (i - 1)) % mod;

		res = dp[k] * fac[n - k] % mod;
		res = (fac[n] - res + mod) % mod;
		cout << res << '\n';
	}
}

namespace Sol_III
{
	const int N = 25;
	int cnt[2] = {0, 0}, lim[N];
	long long dp[N][N], tmp[N], res;
	inline void solve()
	{
		for(int mask = 0; mask < (1 << n); ++mask)
		{
			bool flag = true;
			for(int i = 1; i <= n; ++i)
				if(mask & (1 << (i - 1)))
					if(s[i] == '0')
						flag = false;
			if(!flag) continue;

			cnt[0] = cnt[1] = 0;
			memset(lim, 0, sizeof(lim));
			for(int i = 1, sum = 0; i <= n; ++i)
			{
				if(mask & (1 << (i - 1))) ++cnt[1], ++lim[sum + 1];
				else ++cnt[0], ++sum;
			}

			if(__builtin_popcount(mask) < m) continue;
			
			memset(dp, 0, sizeof(dp));
			dp[n + 1][0] = 1;
			for(int i = n, sum = 0, org = 0, ex = 0; i >= 0; --i)
			{
				for(int j = 0; j <= n; ++j)
					if(dp[i + 1][j])
						Plus(dp[i][j + (i <= cnt[0])], dp[i + 1][j]);
				sum += buc[i]; org += (i <= cnt[0]);
				for(int j = 1; j <= buc[i]; ++j)
				{
					for(int k = 1; k <= n; ++k)
					{
						Plus(dp[i][k - 1], dp[i][k] * k % mod);
					}
				}
				for(int j = 1; j <= lim[i]; ++j)
				{
					for(int k = 0; k <= n; ++k)
					{
						int remain = sum - (org - k) - ex;
						if(remain > 0)
							dp[i][k] = dp[i][k] * remain % mod;
						else dp[i][k] = 0;
					}
					++ex;
				}
			}
			Plus(res, dp[0][0]);
		}
		cout << res << '\n';
	}
}

namespace Sol_IV
{
	const int N = 15;
	long long res; int p[N];
	inline void solve()
	{
		int cnt = 1;
		for(int i = 1; i <= n; ++i) p[i] = i, cnt *= i;
		for(int t = 1; t <= cnt; ++t)
		{
			int sum = 0;
			for(int i = 1; i <= n; ++i)
			{
				int pt = p[i];
				if(sum >= c[pt] || s[i] == '0') ++sum;
			}
			if(n - sum >= m) ++res;
			next_permutation(p + 1, p + n + 1);
		}
		cout << res << '\n';
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	#ifdef LOCAL
	freopen("text.in", "r", stdin);
	freopen("prog.out", "w", stdout);
	freopen("prog.err", "w", stderr);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init_math();
	cin >> n >> m >> s; s = ' ' + s;
	int base = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == '0') ++base;
		if(s[i] == '1') w[++k] = base;
	}
	if(k < m) {cout << 0 << '\n'; return 0;}
	for(int i = 1; i <= n; ++i) cin >> c[i], ++pr[c[i]], ++buc[c[i]];
	for(int i = 1; i <= n; ++i) pr[i] += pr[i - 1];
	
	if(m == n)
		Sol_I::solve();
	else if(m == 1)
		Sol_II::solve();
	else if(n <= 10)
		Sol_IV::solve();
	else if(n <= 18)
		Sol_III::solve();
	return 0;
}
/*
g++ employ.cpp -o employ -O2 -std=c++14 -static -Wall -DLOCAL -Wno-unused-result
./employ
*/