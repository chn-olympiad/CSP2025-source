#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 505, mod = 998244353;
int f[N][N], g[N][N], c[N], fac[N];
char s[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, i, j, k, x, ans = 0;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		c[x]++;
	}
	fac[0] = 1;
	for(i = 1; i <= n; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mod;
		c[i] += c[i - 1];
	}
	f[0][0] = 1;
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j <= i; j++)
			for(k = 0; k <= i; k++)
				g[j][k] = 0;
		if(s[i] == '0')
			for(j = 0; j < i; j++)
				for(k = 0; k < i; k++)
					g[j + 1][k] = (g[j + 1][k] + f[j][k]) % mod;
		else
			for(j = 0; j < i; j++)
				for(k = 0; k < i; k++)
				{
					g[j + 1][k + 1] = (g[j + 1][k + 1] + (ll)f[j][k] * (mod + c[j] - k)) % mod;
					g[j][k + 1] = (g[j][k + 1] + (ll)f[j][k] * (mod - c[j] + k)) % mod;
					g[j][k] = (g[j][k] + f[j][k]) % mod;
				}
		for(j = 0; j <= i; j++)
			for(k = 0; k <= i; k++)
				f[j][k] = g[j][k];
	}
	for(j = 0; j <= n - m; j++)
		for(k = 0; k <= n; k++)
			ans = (ans + (ll)f[j][k] * fac[n - k]) % mod;
	printf("%d\n", ans);
	return 0;
}