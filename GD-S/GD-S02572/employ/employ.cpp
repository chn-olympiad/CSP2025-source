#include <bits/stdc++.h>
using namespace std;

int n, m, s[505], c[505], kly[505], sum, v[505], jl[505];

bool A, B;

long long ans, xlr, jc[505];

const int mod = 998244353;

void dfs(int x, int cnt)
{
	if (cnt >= m)
	{
		ans += jc[n - x + 1];
		ans %= mod;
		return;
	}
	if (x > sum)
	{
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] != 1)
		{
			v[i] = 1;
			dfs(x + 1, cnt + ((jl[x] - 1 - cnt) < c[i]));
			v[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	jc[0] = 1;
	A = B = true;
	for (int i = 1; i <= n; i++)
	{
		scanf("%1d", &s[i]);
		A = A & s[i];
		if (s[i] == 1)
		{
			sum++;
			jl[sum] = i;
		}
		jc[i] = jc[i - 1] * i % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		kly[c[i]]++;
	}
	sort(c + 1, c + n + 1);
	if (sum < m)
	{
		printf("0\n");
		return 0;
	}
	if (sum > 18)
	{
		B = false;
	}
	if (m == n)
	{
		xlr = 1;
		for (int i = 1; i <= n; i++)
		{
			kly[i] += kly[i - 1];
		}
		for (int i = 1, cnt; i <= n; i++)
		{
			if (s[i] == 1)
			{
				++cnt;
				xlr *= (kly[i - 1] - cnt + 1);
				xlr %= mod;
			}
		}
		printf("%lld\n", xlr);
		return 0;
	}
	if (m == 1 || n >= 19)
	{
		ans = xlr = 1;
		for (int i = 1; i <= n; i++)
		{
			kly[i] += kly[i - 1];
			ans *= i;
			ans %= mod;
		}
		for (int i = 1, cnt; i <= n; i++)
		{
			if (s[i] == 1)
			{
				++cnt;
				xlr *= (kly[i - 1] - cnt + 1);
				xlr %= mod;
			}
		}
		printf("%lld\n", (ans - xlr + mod) % mod);
		return 0;
	}
	ans = 0;
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
