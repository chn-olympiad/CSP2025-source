#include <bits/stdc++.h>
typedef long long LL;

int read()
{
	int s = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar()) f ^= (c == '-');
	for (; isdigit(c); c = getchar()) s = s * 10 + (c ^ 48);
	return f ? s : -s;
}
template<typename T> void write(T x, char end = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static int d[100]; int cur = 0;
	do { d[++cur] = x % 10; } while (x /= 10);
	while (cur) putchar(48 ^ d[cur--]);
	putchar(end);
}
template<typename T> void Fmax(T &x, T y){ if (x < y) x = y; }
template<typename T> void Fmin(T &x, T y){ if (y < x) x = y; }
const int MOD = 998244353;
int fplus(int x, int y){ return (x += y) >= MOD ? x - MOD : x; }
int fminus(int x, int y){ return (x -= y) < 0 ? x + MOD : x; }
void Fplus(int &x, int y){ if ((x += y) >= MOD) x -= MOD; }
void Fminus(int &x, int y){ if ((x -= y) < 0) x += MOD; }
int fpow(int x, int y = MOD - 2)
{
	int res = 1;
	for (; y; y >>= 1, x = (LL)x * x % MOD)
		if (y & 1) res = (LL)res * x % MOD;
	return res;
}
const int MAXN = 505;
int n, m, cnt[MAXN], pre[MAXN];
char s[MAXN];
int comb[MAXN][MAXN], fac[MAXN], perm[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read(), scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) cnt[read()]++;
	pre[0] = cnt[0];
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + cnt[i];
	for (int i = 0; i <= n; i++)
	{
		comb[i][0] = perm[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			comb[i][j] = fplus(comb[i - 1][j], comb[i - 1][j - 1]);	
			perm[i][j] = (LL)perm[i][j - 1] * (i - j + 1) % MOD;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = (LL)i * fac[i - 1] % MOD;
	f[0][cnt[0]] = 1;
	int ss = 0;
	for (int i = 1; i <= n; i++)
	{
		memcpy(g, f, sizeof g);
		if (s[i] == '0') memset(f, 0, sizeof f);
		for (int j = i - 1 - ss; j < i; j++)
			for (int k = 0; k <= pre[j]; k++)
			{
				int kk = k;
				int v = g[j][k];
				if (s[i] == '1')
				{
					if (!k) continue;
					v = (LL)v * k % MOD, kk--;
				}
				int rem = ss + (s[i] == '1') - (pre[j] - kk);
				for (int x = 0; x <= cnt[j + 1] && x <= rem; x++)
				{
					int vv = (LL)v * comb[cnt[j + 1]][x] % MOD * perm[rem][x] % MOD;
//					printf("%d %d %d %d %d: %d %d\n", i, j, k, x, rem, v, vv);
					Fplus(f[j + 1][kk + cnt[j + 1] - x], vv);
				}
			}
//		printf("------- %d --------\n", i);
//		for (int j = 0; j <= n; j++)
//			for (int k = 0; k <= n; k++)
//				printf("%d%c", f[j][k], " \n"[k == n]);
		ss += s[i] - '0';
	}
	int ans = 0;
	for (int j = 0; j <= n - m; j++)
		for (int k = 0; k <= pre[j]; k++)
		{
			int rem = ss - (pre[j] - k);
			Fplus(ans, (LL)f[j][k] * perm[pre[n] - pre[j]][rem] % MOD);			
		}
	write((LL)ans * fac[n - ss] % MOD);
	return 0;
} 
