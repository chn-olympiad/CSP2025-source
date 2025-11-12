#include <bits/stdc++.h>
using namespace std;

constexpr int N = 505, MOD = 998244353, M = 18;

int n, m;
array<int, N> s, c, sum, fac, ifac;

array<array<int, M + 1>, 1 << M> f, g;
array<array<int, N>, N> ng, h;

inline int query(int l, int r)
{
	if (l > r) return 0;
	int res = sum[r];
	if (l) res -= sum[l - 1];
	return res;
}

inline int qpow(int a, int b)
{
	int res = 1, base = a;
	while (b)
	{
		if (b & 1) res = 1ll * res * base % MOD;
		base = 1ll * base * base % MOD;
		b >>= 1;
	}
	return res;
} 

inline int binom(int n, int m)
{
	if (n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

inline void add(int &x, int y)
{
	x += y, x >= MOD ? x -= MOD : 0;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char x;
		cin >> x;
		s[i] = x - '0';
	}
	for (int i = 1; i <= n; i++) cin >> c[i], sum[c[i]]++;
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	if (m == n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (!c[i] || !s[i])
			{
				cout << "0\n";
				return 0;
			}
		}
		int res = 1;
		while (n) res = 1ll * res * n % MOD, n--;
		cout << res << "\n";
		return 0;
	}
	if (n <= 18)
	{
		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < (1 << M); j++) g[j].fill(0);
			for (int lst = 0; lst < (1 << M); lst++)
			{
				for (int x = 0; x < i; x++)
				{
					if (!f[lst][x]) continue;
					for (int nx = 0; nx < n; nx++)
					{
						if ((lst >> nx) & 1) continue;
						int val = c[nx + 1], bd = i - 1 - x;
						int nl = lst | (1 << nx), nc = x + (s[i] == 1 && bd < val);
						g[nl][nc] += f[lst][x];
						g[nl][nc] >= MOD ? g[nl][nc] -= MOD : 0;
					}
				}
			}
			for (int j = 0; j < (1 << M); j++) f[j] = g[j];
		} 
		int ans = 0;
		for (int i = m; i <= n; i++)
		{
			ans += f[(1 << n) - 1][i], ans >= MOD ? ans -= MOD : 0;
		}
		cout << ans << "\n";
	} 
	else
	{
		fac[0] = 1;
		for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[N - 1] = qpow(fac[N - 1], MOD - 2);
		for (int i = N - 2; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD; 
		// ng[i][j][k]: first i, j 个，k 个未钦定
		int cc = 0;
		ng[0][0] = 1; 
		for (int i = 1; i <= n; i++)
		{
			cc += (i > 1 && !s[i - 1]);
			for (int j = 0; j <= n; j++) h[j].fill(0);
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k + j < i; k++)
				{
					if (!ng[j][k]) continue;
					if (s[i] == 1)
					{
						add(h[j][k + 1], ng[j][k]);
						// 钦定其为 0
						int cnt = query(0, j) - (j - cc) - (i - 1 - j - k); 
						cnt = max(cnt, 0);
						int val = 1ll * ng[j][k] * cnt % MOD;
						int cntc = query(j + 1, j + 1);
						for (int c = 0; c <= cntc && c <= k; c++) // c个数=j+1
						{
							int nval = 1ll * val * binom(k, c) % MOD * binom(cntc, c) % MOD * fac[c] % MOD;
							add(h[j + 1][k - c], nval);
						} 
					}
					else
					{
						int cntc = query(j + 1, j + 1);
						for (int c = 0; c <= cntc && c <= k; c++) // c个数=j+1
						{
							// a[i] > j + 1
							int val = 1ll * ng[j][k] * binom(k, c) % MOD * binom(cntc, c) % MOD * fac[c] % MOD;
							add(h[j + 1][k - c + 1], val);
							// a[i] = j + 1
							if (c + 1 <= cntc)
							{
								int val = 1ll * ng[j][k] * binom(k, c) % MOD * binom(cntc, c + 1) % MOD * fac[c] % MOD * (c + 1) % MOD;
								add(h[j + 1][k - c], val);
							}
							// a[i] <= j
							int cnt = query(0, j) - (j - cc) - (i - 1 - j - k); 
							cnt = max(cnt, 0);
							val = 1ll * ng[j][k] * cnt % MOD * binom(k, c) % MOD * binom(cntc, c) % MOD * fac[c] % MOD;
							add(h[j + 1][k - c], val); 
						}
					}
				}
			}
			for (int j = 0; j <= n; j++) 
			{
				ng[j] = h[j];
			}
		}
		int ans = 0;
		for (int j = 0; j <= n - m; j++)
		{
			int k = query(j + 1, n);
			int val = ng[j][k];
			ans += 1ll * val * fac[k] % MOD;
			ans >= MOD ? ans -= MOD : 0;
		}
		cout << ans << "\n";
	}
	return 0;
}
