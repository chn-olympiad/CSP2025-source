#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
inline void write_ll(long long x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write_ll(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 5e5 + 10;
const int Mod = 998244353;
int a[N];
int cnt;
int sum[N];
int d[N], cd;
int ans = 0;
void dfs(int la, int t, int tk, int sm)
{
	if (sm + sum[t] - sum[la] <= tk)
	{
		return ;
	}
	if (sm > tk)
	{
		ans++;
		ans %= Mod;
	}
	for (int i = la + 1; i <= t; i++)
	{
		dfs(i, t, tk, sm + a[i]);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
	if (n < 3)
	{
		write(0);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3])
		{
			write(1);
		}
		else
		{
			write(0);
		}
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		dfs(0, i - 1, a[i], 0);
	}
	write(ans);
	return 0;
}