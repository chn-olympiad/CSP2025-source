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
const int N = 1010;
int num[N];
int cnt;
struct node{
	int w;
	int id;
	void readn(int i)
	{
		w = read();
		id = i;
	}
	bool operator < (const node& xx) const{
		return w > xx.w;
	}
} st[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	n = read();
	m = read();
	int mt = n * m;
	for (int i = 1; i <= mt; ++i)
	{
		st[i].readn(i);
	}
	sort(st + 1, st + mt + 1);
	int xw = 0;
	for (int i = 1; i <= mt; ++i)
	{
		if (st[i].id == 1)
		{
			xw = i;
		}
	}
	int c = xw / n;
	int y = (xw - 1) % n + 1;
	if (y == n)
	{
		if (c & 1)
		{
			write(c);
			putchar(' ');
			write(n);
		}
		else
		{
			write(c);
			putchar(' ');
			write(1);
		}
		return 0;
	}
	++c;
	if (c & 1)
	{
		write(c);
		putchar(' ');
		write(y);
	}
	else
	{
		write(c);
		putchar(' ');
		write(n - y + 1);
	}
	return 0;
}