#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 5005, mod = 998244353;
int n, a[N], ans;
int c[505][505], fact[N], infact[N];

int pw(int a, int k)
{
	int res = 1;
	while(k)
	{
		if(k & 1) res = (1ll * res * a) % mod;
		a = (1ll * a * a) % mod;
		k >>= 1;
	}
	return res;
}

int t[N], res;
bool st[N];
void dfs(int cnt, int start)
{
	if(cnt >= 4)
		if(res > (t[cnt - 1] << 1)) ans++, ans %= mod;
	rep(i, start, n)
	{
		if(st[i]) continue;
		st[i] = 1;
		t[cnt] = a[i];
		res += a[i];
		dfs(cnt + 1, i + 1);
		res -= a[i];
		st[i] = 0;
	}
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", a + i);
	if(n <= 20)
	{
		sort(a + 1, a + n + 1);
		dfs(1, 1);
		printf("%lld", ans);
	}
	else
	{
		if(n <= 500)
		{
			rep(i, 1, n) rep(j, 1, n)
			{
				if(i == 1) c[i][j] = j;
				else c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % mod;
			}
			rep(i, 3, n) ans = (ans + c[i][n]) % mod;
			printf("%lld", ans);
		}
		else
		{
			fact[1] = infact[1] = 1;
			rep(i, 2, n)
			{
				fact[i] = (1ll * fact[i - 1] * i) % mod;
				infact[i] = 1ll * pw(fact[i], mod - 2) % mod;
			}
			rep(i, 3, n) ans = (ans + 1ll * fact[n] * infact[i] % mod * infact[n - i]) % mod;
			printf("%lld", ans + 1);
		}
	}
	return 0;
}

