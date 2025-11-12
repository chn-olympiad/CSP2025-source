#include<bits/stdc++.h>

int n, m, data[505], hard[505];
int chace[20], vis[20];

long long dfs(int pos = 1)
{
	if(pos > n)
	{
		int cnt = 0, get = 0;
		for(int i = 1; i <= n; ++i)
		{
			//std::cout << data[chace[i]] << hard[i] << std::endl;
			if(hard[i] != 1 || data[chace[i]] <= cnt)
			{
				cnt += 1;
			}
			else 
			{
				get += 1;
			}
		}
		if(get >= m)
		{
			//std::cout << cnt << get << std::endl;
			return 1;
		}
		return 0;
	}
	
	long long ans = 0;
	
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			vis[i] = true;
			chace[pos] = i;
			ans += dfs(pos + 1);
			vis[i] = false;
		}
	}
	return ans % 998244353;
}

long long fac(int u)
{
	long long ans = 1;
	for(int i = 1; i <= n; ++i)
	{
		ans *= i;
		ans %= 998244353;
	} 
	return ans;
}

long long ant(int u)
{
	long long ans = 1;
	int k = 998244353 - 2;
	while(k)
	{
		if(k & 1)
		{
			ans *= u;
			ans %= 998244353;
		}
		u *= u;
		u %= 998244353;
		k /= 2;
	}
	return ans;
}

void run()
{
	scanf("%d", &n);
	scanf("%d", &m);
	char ch;
		scanf("%c", &ch);
	for(int i = 1; i <= n; ++i)
	{
		char ch;
		scanf("%c", &ch);
		hard[i] = ch - '0';
	}
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", data + i);
	}
	
	int ans;
	
	
	if(n <= 18)
	{
		ans = dfs();
	}
	else
	{
		ans = fac(n) * ant(fac(m)) % 998244353 * ant(fac(n-m)) % 998244353;
	}
	
	printf("%d", ans);
}

signed main()
{
	freopen("employ.in", "r",stdin);
	freopen("employ.out", "w", stdout);
	run();
	return 0;
}
