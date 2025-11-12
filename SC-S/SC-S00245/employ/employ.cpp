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
const int N = 1e5 + 10;
const int Mod = 998224353;
int n, m;
int c[N], vis[N];
long long ans;
string s;
int answ[N], ww;
long long get_jch(long long t)
{
	long long mult = 1, c = t;
	while(c)
	{
		mult = (mult * c) % Mod;
		c--;
	}
	return mult % Mod;
}
void dfs(int x, int lu, int gn)
{
	if (lu + (n - x + 1) < m)
	{
		return ;
	}
	if (lu == m)
	{
		ans = (ans % Mod + get_jch(n - x + 1) % Mod) % Mod;
		return ;
	}
	if (x == n + 1)
	{
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			answ[x] = i;
			if (gn >= c[i])
			{
				dfs(x + 1, lu, gn + 1);
			}
			else if (s[x - 1] == '1')
			{
				dfs(x + 1, lu + 1, gn);
			}
			else
			{
				dfs(x + 1, lu, gn + 1);
			}
			answ[x] = 0;
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read();
	m = read();
	cin >> s;
	bool aw = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '0')
		{
			aw = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = read();
	}
	if (!aw)
	{
		write_ll(get_jch(n) % Mod);
		return 0;
	}
	if (m == n)
	{
		printf("0");
		return 0;
	}
	dfs(1, 0, 0);
	write_ll(ans);
	return 0;
}