#include <bits/stdc++.h>
using namespace std;
struct qu
{
	int l, r;
}quj[5000005];
long long a[500005], q[500005];
bool cmp(qu x, qu y)
{
	if (x.r != y.r)
	{
		return x.r < y.r;
	}
	return x.l > y.l;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	long long k;
	cin >> n >> k;
	bool fy = true, fly = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			fy = false;
		}
		if (a[i] > 1)
		{
			fly = false;
		}
	}
	if (fy)
	{
		if (k == 0)
		{
			cout << n / 2;
		}
		else if (k == 1)
		{
			cout << n;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	if (fly)
	{
		if (k == 0)
		{
			int cnt = 0, now = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0)
				{
					cnt++;
					now = 0;
				}
				if (a[i] == 1)
				{
					if (now == 0)
					{
						now = 1;
					}
					else
					{
						cnt++;
						now = 0;
					}
				}
			}
			cout << cnt;
		}
		else if (k == 1)
		{
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 1) cnt++;
			}
			cout << cnt;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		q[i] = q[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if ((q[j] ^ q[i - 1]) == k)
			{
				if (cnt <= 5000000)
				{
					cnt++;
					quj[cnt].l = i;
					quj[cnt].r = j;
				}
			}
		}
	}
	sort(quj + 1, quj + cnt + 1, cmp);
	int ans = 0, now = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (now < quj[i].l)
		{
			ans++;
			now = quj[i].r;
		}
	}
	cout << ans;
	return 0;
}
