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
const int N = 5e5 + 10;
int a[N];
int cnt;
int sum[N];
struct node
{
	int l;
	int r;
	bool operator < (const node& xx) const{
		return (r != xx.r) ? (r < xx.r) : (l < xx.l);
	}
};
node qj[N];
int one[N];
int oc = 0;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	n = read();
	k = read();
	bool flg = 0;
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
		if (a[i] == 1)
		{
			one[++oc] = i;
		}
		if (a[i] > 1)
		{
			flg = 1;
		}
		sum[i] = sum[i - 1] ^ a[i];
	}
	if (!flg)
	{
		if (!k)
		{
			for (int i = 2; i <= oc; ++i)
			{
				qj[++cnt] = (node){one[i - 1], one[i]};
			}
			for (int i = 1; i <= n; ++i)
			{
				if (!a[i])
				{
					qj[++cnt] = (node){i, i};
				}
			}
			sort(qj + 1, qj + cnt + 1);
			int rr = qj[1].r, nc = 1;
			for (int i = 2; i <= cnt; ++i)
			{
				if (qj[i].l > rr)
				{
					rr = qj[i].r;
					nc++;
				}
			}
			write(nc);
		}
		else
		{
			for (int i = 1; i <= oc; ++i)
			{
				qj[++cnt] = (node){one[i], one[i]};
			}
			sort(qj + 1, qj + cnt + 1);
			int rr = qj[1].r, nc = 1;
			for (int i = 2; i <= cnt; ++i)
			{
				if (qj[i].l > rr)
				{
					rr = qj[i].r;
					nc++;
				}
			}
			write(nc);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; --j)
		{
			if ((sum[i] ^ sum[j - 1]) == k)
			{
				qj[++cnt] = node{j, i};
				break;
			}
		}
	}
	sort(qj + 1, qj + cnt + 1);
	int rr = qj[1].r, nc = 1;
	for (int i = 2; i <= cnt; ++i)
	{
		if (qj[i].l > rr)
		{
			rr = qj[i].r;
			nc++;
		}
	}
	write(nc);
	return 0;
}