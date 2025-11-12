#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n, m, k;
struct lp
{
	long long fr, to, ds, country;
};
int bsq[10001];
long long st[11], use[11];
bool llp (lp a, lp b)
{
	return a.ds < b.ds;
}
lp a[4000001];
int fa (int x)
{
	return bsq[x] == 0 ? x : fa (bsq[x]);
}
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
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	n = read ();
	m = read ();
	k = read ();
	int stt = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].fr >> a[i].to >> a[i].ds;
		a[i].country = -1;
	}
	for (int i = 1; i <= k; i++)
	{
		st[i] = read ();
		stt += st[i];
		for (int j = 1; j <= n; j++)
		{
			a[m + i * n + j - n].fr = n + i;
			a[m + i * n + j - n].to = j;
			cin >> a[m + i * n + j - n].ds;
			a[m + i * n + j - n].country = i;
		}
	}
	m += k * n;
	n += k;
	long long count = stt;
	int d = 0;
	sort (a + 1, a + m + 1, llp);
	for (int i = 1; i <= m && d < n - 1; i++)
	{
		int a1 = fa (a[i].fr), a2 = fa (a[i].to);
		if (a1 != a2)
		{
			bsq[a2] = a1;
			count += a[i].ds;
			d++;
		}
	}
	for (int j = k; j >= 1; j--)
	{
		memset (bsq, 0, sizeof (bsq));
		long long countt = stt - st[j];
		d = 0;
		int xx[200001];
		for (int i = 1, cnt = 0; i <= m && d < n - 1; i++)
		{
			if (a[i].country != j && a[i].country != -2 && use[a[i].fr] != -1)
			{
				int a1 = fa (a[i].fr), a2 = fa (a[i].to);
				if (a1 != a2)
				{
					bsq[a2] = a1;
					countt += a[i].ds;
					d++;
				}
			}
			if (a[i].country == j)
			{
				xx[++cnt] = i;
			}
		}
		if (countt < count)
		{
			count = countt;
			stt -= st[j];
			for (int i = 1; i <= n; i++)
			{
				a[xx[i]].country = -2;
			}
		}
		else
		{
			n--;
			use[j] = -1;
		}
	}
	cout << count;

	return 0;
}
