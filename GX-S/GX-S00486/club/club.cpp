#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int t, n;
struct lp
{
	int a, aa, c;
};
bool llp (lp a, lp b)
{
	return a.c < b.c;
}
lp a[100001];
int b[100001];
inline int read ()
{
	int f = 1, x = 0;
	char c = getchar ();
	while (c > '9' || c < '0')
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar ();
	}
	return x * f;
}
int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	t = read ();
	for (; t > 0; t--)
	{
		n = read ();
		int count = 0;
		int ac = 0, bc = 0, cc = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = read (), y = read (), z = read ();
			if (x >= y && x >= z)
			{
				a[i].aa = 1;
				a[i].a = x;
				ac++;
				a[i].c = x - max (y, z);
			}
			else
			{
				if (y >= x && y >= z)
				{
					a[i].aa = 2;
					a[i].a = y;
					bc++;
					a[i].c = y - max (x, z);
				}
				else
				{
					a[i].aa = 3;
					a[i].a = z;
					cc++;
					a[i].c = z - max (x, y);
				}
			}
		}
		if (ac >= bc && ac > cc)
		{
			ac = 1;
		}
		else
		{
			if (bc >= ac && bc > cc)
			{
				ac = 2;
			}
			else
			{
				ac = 3;
			}
		}
		sort (a + 1, a + n + 1, llp);
		int x = 0, cnt = 0, cnnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].aa == ac)
			{
				if (x == n / 2)
				{
					count += a[i].a;
					count -= b[++cnnt];
				}
				else
				{
					x++;
					count += a[i].a;
					b[++cnt] = a[i].c;
				}
			}
			else
			{
				count += a[i].a;
			}
		}
		cout << count << endl;
	}

	return 0;
}
