#include <cstdio>
#include <iostream>
using namespace std;
long long ans;
long long a[5001], n;
void dfs(long long w, long long x, long long y, long long z)
{
	if (y == n + 1)
	{
		if (w < 3)
		{
			return; 
		}
		if (x <= z * 2)
		{
			return;
		}
		ans ++;
		ans %= 998244353;
		return;
	}
	dfs(w + 1, x + a[y], y + 1, max(z, a[y]));
	dfs(w, x, y + 1, z);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);	
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i ++)
	{
		scanf("%lld", a + i);
	}
	dfs(0, 0, 1, 0);
	printf("%lld", ans);
	return 0;
}
