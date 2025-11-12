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
const int N = 1e5 + 10;
const int Mod = 998224353;
int n, q;
struct node{
	string s, cgs;
	bool operator < (const node& xx)
	{
		return (s != xx.s) ? (s < xx.s) : (cgs < xx.cgs);
	}
} cg[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read();
	q = read();
	for (int i = 1; i <= n; ++i)
	{
		cin >> cg[i].s >> cg[i].cgs;
	}
	sort(cg + 1, cg + n + 1);
	while (q--)
	{
		string t, cgt;
		cin >> t >> cgt;
		int lt = t.size();
		int lc = cgt.size();
		if (lt != lc)
		{
			write(0);
			putchar('\n');
			continue;
		}
		int dl = -1, dr = -1, anss = 0;
		for (int i = 0; i < lt; ++i)
		{
			if (t[i] != cgt[i])
			{
				if (dl == -1)
				{
					dl = dr = i;
				}
				else
				{
					dr = i;
				}
			}
		}
		string ss = t.substr(dl, dr - dl + 1);
		string cs = cgt.substr(dl, dr - dl + 1);
		for (int i = dl; i >= 0; --i)
		{
			if (i < dl)
			{
				ss = t[i] + ss;
				cs = cgt[i] + cs;
			}
			for (int j = dr; j < lt; ++j)
			{
				if (i > dr)
				{
					ss = ss + t[i];
					cs = cs + cgt[i];
				}
				for (int k = 1; k <= n; ++k)
				{
					if (cg[k].s == ss && cg[k].cgs == cs)
					{
						anss++;
					}
				}
			}
		}
		write(anss);
		putchar('\n');
	}
	return 0;
}