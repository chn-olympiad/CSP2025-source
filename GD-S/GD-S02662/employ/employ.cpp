#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
const ll mod = 998244353;
int n, m, s[N], sq[N];
int c[N], sc[N];
ll f[2][N][N];
ll mul[N], inv[N], inmul[N];
void ma(ll &x, ll y)
{
	x = (x + y) % mod;
}
ll com(ll n, ll m)
{
	if(n < m || m < 0)return 0;
	return mul[n] * inmul[m] % mod * inmul[n - m] % mod;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	mul[0] = inv[0] = inmul[0] = 1;
	mul[1] = inv[1] = inmul[1] = 1;
	for(int i = 2; i <= 500; i++)
	{
		mul[i] = mul[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		inmul[i] = inmul[i - 1] * inv[i] % mod;
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		char c = getchar();
		while(c != '0' && c != '1')c = getchar();
		s[i] = c - '0';
		sq[i] = sq[i - 1] + s[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		c[k]++;
	}
	sc[0] = c[0];
	for(int i = 1; i <= n; i++)sc[i] = sc[i - 1] + c[i];
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int now = (i&1), pre = now^1;
		memset(f[now], 0, sizeof f[now]);
		for(int j = 0; j < i; j++)
		{
			int p = i - 1 - j;
			for(int k = 0; k <= sq[i - 1]; k++)
			{
				int w = sq[i - 1] - k;
				if(s[i])
				{
					ma(f[now][j + 1][k], f[pre][j][k]);
					for(int s = 0; s <= c[p + 1] && s <= w; s++)
						ma(f[now][j][k + s + 1], f[pre][j][k] * com(w, s) % mod * mul[c[p + 1]] % mod * inmul[c[p + 1] - s] % mod * (sc[p] - k + mod) % mod);
				}
				else
				{
					for(int s = 0; s <= c[p + 1] && s <= w; s++)
						ma(f[now][j][k + s], f[pre][j][k] * com(w, s) % mod * mul[c[p + 1]] % mod * inmul[c[p + 1] - s]);
				}
			}
		}
	}
	ll ans = 0;
	for(int j = m; j <= n; j++)
		for(int k = 0; k <= sq[n]; k++)
		{
			int p = n - j, w = sq[n] - k;
			ma(ans, f[n&1][j][k] * com(n - sc[p], w) % mod * mul[w]);
		}
	printf("%lld\n", ans * mul[n - sq[n]] % mod);
	return 0;
}
