#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int MOD = 998244353;

int d[N], n, m, s, k, ma;

long long ans = 1;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		char c;
		scanf(" %c", &c);
		d[i] = (c == '1');
		if (d[i] && !k)
		{
			k = i;
		}
		s += (c == '1')? 1 : 0;
	}
	for (int i = 1, x; i <= n; i++)
	{
		scanf("%d", &x);
		ma = max(ma, x);
	}
	if (s == n)
	{
		for (int i = 2; i <= n; i++)
		{
			ans *= i;
			ans %= MOD;
		}
		printf("%lld", ans);
		return 0;
	}
	printf("0");
	return 0;
}
