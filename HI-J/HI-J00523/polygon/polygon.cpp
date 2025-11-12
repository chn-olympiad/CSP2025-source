#include<bits/stdc++.h>
#define i64 long long

i64 constexpr MOD = 998244353;
i64 constexpr N = 5005;
i64 fac[N], anfc[N];
i64 cnt[N], elcnt[N], n;


i64 powm(i64 base)
{
	i64 p = MOD - 2;
	i64 ans = 1;
	while(p)
	{
		if(p & 1)
		{
			ans *= base;
			ans %= MOD;
		}
		base *= base;
		base %= MOD;
		p /= 2;
	}
	return ans;	
}

void init()
{
	fac[0] = anfc[0] = 1;
	for(int i = 1; i <= 5000; ++i)
	{
		fac[i] = fac[i-1] * i % MOD;
	}
	for(int i = 1; i <= 5000; ++i)
	{
		anfc[i] = powm(fac[i]);
	}
}

i64 xC(i64 n, i64 m)
{
	return fac[n] * anfc[m] % MOD * anfc[n-m] % MOD;
}

void in_and_cnt()
{
	scanf("%lld", &n);
	for(int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		cnt[x] += 1;
	}
	for(int i = 5000; i > 0; --i)
	{
		elcnt[i] = elcnt[i+1] + cnt[i+1];
	}
}

i64 dfs(i64 sum = 0, i64 biggest = 0, i64 pos = 1)
{
	if(pos > 100)
	{
		if(sum > 2 * biggest)
		{
			return 1;
		}
		return 0;
	}
	
	i64 ans = 0;
	// choice = 0
	ans += dfs(sum, biggest, pos + 1);
	for(int choice = 1; choice <= cnt[pos]; ++choice)
	{
		ans += dfs(sum + choice * pos, pos, pos + 1) * xC(cnt[pos], choice) % MOD;
	}
	ans %= MOD;
	return ans;
}

void run()
{
	init();
	in_and_cnt();
	printf("%lld\n", dfs());
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	run();
	return 0;
}

