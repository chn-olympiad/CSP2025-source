#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5007;

int n;

#define int long long

const int mod = 998244353;

int a[MAXN], cnt[MAXN];

int bin_pow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

struct Sub1 {
	int ans = 0;
	bool bz[27];
	void dfs(int x, int mx, int sum)
	{
		if(x > n)
		{
			if(sum > mx * 2)
				ans = (ans + 1) % mod; 
			return ;
	  	}
	  	bz[x] = 1;
	  	dfs(x + 1, max(mx, a[x]), sum + a[x]);
	  	bz[x] = 0;
	  	dfs(x + 1, mx, sum);
	  	return ;
	}
	void sol()
	{
		dfs(1, 0, 0);
		printf("%lld\n", ans);
	}
} _;

struct Sub2 {
	int fac[MAXN], inv[MAXN];
	void init(int n = 5000)
	{
		fac[0] = 1;
		for(int i = 1; i <= n; i++)
			fac[i] = fac[i - 1] * i % mod;
		inv[n] = bin_pow(fac[n], mod - 2);
		for(int i = n - 1; i >= 0; i--)
			inv[i] = inv[i + 1] * (i + 1) % mod;
		return ;
	}
	int C(int x, int y)
	{
		if(x < y or x < 0 or y < 0)
			return 0;
		return fac[x] * inv[y] % mod * inv[x - y] % mod;
	}
	void sol()
	{
		init();
		int cnt1 = 0, cnt0 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1)
				++cnt1;
				
			else
				++cnt0;
		}
		if(cnt1 < 3)
		{
			puts("0");
			return ;
		}
		int ans = 0;
		int pw = bin_pow(2, cnt0);
		for(int i = 3; i <= cnt1; i++)
			ans = (ans + C(cnt1, i) * pw % mod) % mod;
		printf("%lld\n", ans);
	}
} __;

struct Sub3 {
	int f[MAXN][MAXN];
	void sol()
	{
		int m = 0;
		for(int i = 1; i <= n; i++)
			m = max(m, a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 0; i <= n; i++)
			f[i][0] = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = m; j >= 1; j--)
				f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
			for(int j = a[i]; j <= m; j++)
				f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
		}
		int res = 0;
		for(int i = 3; i <= n; i++)
		{
			int ans = bin_pow(2, i - 1) - 1;
			int sum = 0;
			for(int j = 1; j <= a[i]; j++)
				sum = (sum + f[i - 1][j]) % mod;
			res = (res + (ans - sum + mod) % mod) % mod;
		}
		printf("%lld", res);
	}
} ___;

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int mx = 0;
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), mx = max(a[i], mx);
	
	if(mx <= 1)
	{
		__.sol();
		return 0;
	}
	
	if(n <= 20)
	{
		_.sol();
		return 0;
	}
	
	___.sol();
	
	return 0;
}
