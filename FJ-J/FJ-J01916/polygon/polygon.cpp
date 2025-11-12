#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mod = 998244353;
const int N = 5e3 + 10;
int n, a[N], sum[N], num;
LL fact[N], infact[N], ans;
vector<bool> g;

void dfs(int dep)
{
	if(dep > n)
	{
		int cnt = 0, mx = 0;
		LL sum = 0;
		for(int i = 0;i < n; ++ i)
			if(g[i])
			{
				mx = max(mx, a[i + 1]);
				cnt ++, sum += a[i + 1];
			}
		if(cnt >= 3 && mx * 2 < sum)
			ans = (ans + 1) % mod;
		return ;
	}
	g.push_back(true);
	dfs(dep + 1);
	g.pop_back();
	g.push_back(false);
	dfs(dep + 1);
	g.pop_back();
}

LL qmi(LL a, LL p)
{
	LL res = 1;
	while(p)
	{
		if(p & 1)
			res = res * a % mod;
		a = a * a % mod;
		p >>= 1;
	}
	return res;
}

LL C(LL n, LL m)
{
	if(n == m)
		return 1;
	return fact[n] * infact[n - m] % mod * infact[m] % mod;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1;i <= n; ++ i)
		scanf("%d", &a[i]), num = max(num, a[i]);
	if(num == 1)
	{
		fact[0] = 1;
		for(int i = 1;i <= n; ++ i)
		{
			fact[i] = fact[i - 1] * i % mod;
			infact[i] = qmi(fact[i], mod - 2);
		}
		for(int i = 3;i <= n; ++ i)
			ans = (ans + C(n, i)) % mod;
		printf("%lld", ans);
		return 0;
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}
