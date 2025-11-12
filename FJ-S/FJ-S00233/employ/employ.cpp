#include <cstdio>
#include <algorithm>
#define N 505
using namespace std;

typedef long long ll;
const int mod = 998244353;

int n, m, ans, c[N], cnt[N], scnt[N], f[N][N][N];
int fac[N], C[N][N];
char s[N];

int add (int &x, ll y) {return x = (x + y) % mod;}

void init (int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		fac[i] = (ll) fac[i - 1] * i % mod;
	}
	for (int i = 0; i <= n; i ++)
	{
		for (int j = C[i][0] = 1; j <= i; j ++)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	return ;
}

int main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%d", &c[i]), cnt[c[i]] ++;
	}
	scnt[0] = cnt[0];
	for (int i = 1; i <= n; i ++)
	{
		scnt[i] = scnt[i - 1] + cnt[i];
	}
	init (n);
	f[0][0][cnt[0]] = 1;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j <= i; j ++)
		{
			for (int k = max (scnt[j] - i, 0); k <= scnt[j]; k ++)
			{
				if (!f[i][j][k]) continue;
				int d = i - (scnt[j] - k), c = cnt[j + 1];
				if (s[i + 1] == '0')
				{
					for (int u = 0; u <= min (c, d); u ++)
					{
						int coef = (ll) C[d][u] % mod * C[c][u] % mod * fac[u] % mod;
						// let (i + 1) wins
						add (f[i + 1][j + 1][k + c - u], (ll) f[i][j][k] * coef);
						// let (i + 1) loses
						add (f[i + 1][j + 1][k + c - u - 1], (ll) f[i][j][k] * coef % mod * (k + c - u));
					}
				}
				else
				{
					// let (i + 1) wins
					add (f[i + 1][j][k], f[i][j][k]);
					// let (i + 1) loses
					for (int u = 0; u <= min (c, d); u ++)
					{
						add (f[i + 1][j + 1][k + c - u - 1], (ll) f[i][j][k] * C[d][u] % mod * C[c][u] % mod * fac[u] % mod * k);
					}
				}
			}
		}
	}
	for (int i = 0; i <= n - m; i ++)
	{
		add (ans, (ll) f[n][i][0] * fac[scnt[n] - scnt[i]]);
	}
	printf ("%d", ans);
	return 0;
}
