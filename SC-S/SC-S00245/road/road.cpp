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
inline long long read_ll()
{
	long long x = 0, f = 1;
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
const int N = 1e5 + 10;
int n, m, k;
int fa[N];
struct edge{
	int u, v;
	long long w;
	void reade()
	{
		u = read();
		v = read();
		w = read_ll();
	}
	bool operator < (const edge& xx)
	{
		return w < xx.w;
	}
} e[N];
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
}
int find(int x)
{
	if (fa[x] == x)
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
long long kruskal()
{
	long long anss = 0;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
	{
		int x = e[i].u;
		int y = e[i].v;
		int fax = find(x);
		int fay = find(y);
		if (fax != fay)
		{
			fa[fax] = fay;
			anss += e[i].w;
		}
	}
	return anss;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	init();
	for (int i = 1; i <= m; i++)
	{
		e[i].reade();	
	}
	write_ll(kruskal());
	return 0;
}