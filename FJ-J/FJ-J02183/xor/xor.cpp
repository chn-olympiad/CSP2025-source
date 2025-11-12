#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], xo[500005], ans, cnt, nowr;
struct q
{
	int l, r;
}y;
vector <q> v;
bool cmp(q a, q b)
{
	if (a.r == b.r)
	{
		return a.l < b.l;
	}
	return a.r < b.r;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 1)
		{
			xo[i] = a[i];
		}
		else
		{
			xo[i] = xo[i - 1] ^ a[i];
		}
	}
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i == j)
			{
				if (a[i] == k)
				{
					y.l = i;
					y.r = j;
					v.push_back(y);
					cnt++;
				}
			}
			else
			{
				if (i == 1)
				{
					if (xo[j] == k)
					{
						y.l = i;
						y.r = j;
						v.push_back(y);
						cnt++;
					}
				}
				else
				{
					int x = xo[j] ^ xo[i - 1];
					if (x == k)
					{
						y.l = i;
						y.r = j;
						v.push_back(y);
						cnt++;
					}
				}
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	ans = 1;
	nowr = v[0].r;
	for (int i = 1; i <= cnt - 1; i++)
	{
		if (v[i].l > nowr)
		{
			ans++;
			nowr = v[i].r;
		}
	}
	cout << ans;
	return 0;
}
