#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL Mod = 998244353;
LL ans;
const int N = 5005;
int n, a[N], m, maxn;
//bool l[N];

LL dfs(int x, int maxx, int sum, int num)
{
	if(num == m)
	{
		if(sum > maxx * 2) 
		{
//			for(int i = 1; i <= n; i++) printf("%d ", l[i]);
//			printf("| num:%d, m:%d, sum:%d, maxx:%d;", num, m, sum, maxx);
//			puts("");
			return 1;
		}
		else return 0;
	}
	if(x == n + 1) return 0;
//	l[x] = 1;
	LL res = dfs(x + 1, max(maxx, a[x]), sum + a[x], num + 1);
//	l[x] = 0;
	return (res + dfs(x + 1, maxx, sum, num)) % Mod;
}

int main()
{
	//回调露娜
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), maxn = max(maxn, a[i]);
	if(maxn <= 1)
	{
		for(m = 3; m <= n; m++)
		{
			LL res1 = 1, res2 = 0;
			for(int j = n; j > n - m; j++) 
			{
				res1 = res1 * j;
				if(res1 >= Mod) res1 %= Mod;
			}
			for(int j = 1; j <= m; j++) 
			{
				res2 = res2 * j;
				if(res2 >= Mod) res2 %= Mod;
			}
			ans += res1 / res2;
		}
	}
	else for(m = 3; m <= n; m++)
	{
		ans = (ans + dfs(1, 0, 0, 0)) % Mod;
	}
	printf("%lld", ans);
	return 0;
}