#include <cstdio>
#include <iostream>
#include <algorithm>
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
const int N = 1e5 + 10;
struct node{
	int lk, lk2, lk3;
	void readn()
	{
		lk = read();
		lk2 = read();
		lk3 = read();
	}
} a[N];
bool cmp_A(node x, node y)
{
	return x.lk > y.lk;
}
int chb[N], cha[N];
int maxth(int x, int y, int z)
{
	return max(max(x, y), z);
}
int chac, ge[5], mx;
void dfs(int x, int aa, int bb, int cc, int n, int sm)
{
	if (aa > n / 2 || bb > n / 2 || cc > n / 2)
	{
		return ;
	}
	if (x == n + 1)
	{
		mx = max(mx, sm);
		return ;
	}
	dfs(x + 1, aa + 1, bb, cc, n, sm + a[x].lk);
	dfs(x + 1, aa, bb + 1, cc, n, sm + a[x].lk2);
	dfs(x + 1, aa, bb, cc + 1, n, sm + a[x].lk3);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	t = read();
	bool oa = 0, ta = 0;
	while (t--)
	{
		chac = 0;
		oa = 0;
		ta = 0;
		mx = 0;
		ge[1] = ge[2] = ge[3] = 0;
		n = read();
		for (int i = 1; i <= n; ++i)
		{
			a[i].readn();
			if (a[i].lk - a[i].lk2 > 0)
			{
				cha[i] = a[i].lk - a[i].lk2;
			}
			else
			{
				chb[i] = a[i].lk2 - a[i].lk;
			}
			if (a[i].lk2)
			{
				oa = 1;
			}
			if (a[i].lk3)
			{
				ta = 1;
			}
		}
		if (!ta && !oa)
		{
			sort(a + 1, a + n + 1, cmp_A);
			int sum = 0;
			for (int i = 1; i <= n / 2; ++i)
			{
				sum += a[i].lk;
			}
			write(sum);
			continue;
		}
		else if (!ta)
		{
			int z = 0, y = 0, sum = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (a[i].lk > a[i].lk2)
				{
					++z;
					sum += a[i].lk;
				}
				else
				{
					++y;
					sum += a[i].lk2;
				}
			}
			sort(cha + 1, cha + n + 1);
			sort(chb + 1, chb + n + 1);
			int swp = 0;
			while (z > y)
			{
				swp++;
				--z;
				++y;
				sum -= cha[swp];
			}
			while (z < y)
			{
				swp++;
				++z;
				--y;
				sum -= chb[swp];
			}
			write(sum);
			putchar('\n');
		}
		else
		{
			dfs(1, 0, 0, 0, n, 0);
			write(mx);
			putchar('\n');
		}
	}
	return 0;
}