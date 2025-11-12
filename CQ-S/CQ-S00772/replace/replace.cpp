#include<bits/stdc++.h>
using namespace std;
long long n, q, t, x, y, s, c[5005], d[5005], u[5005], p = 13331, w = 998244353;
string a, b;
map<long long, long long> v; 
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		x = 0;
		y = 0;
		for (int j = 0; j < a.size(); j++)
		{
			x = (x * p + (a[j] - 'a')) % w;
		}
		for (int j = 0; j < b.size(); j++)
		{
			y = (y * p + (b[j] - 'a')) % w;
		}
		v[x] = y + 1;
	}
	while (q--)
	{
		cin >> a >> b;
		s = 0;
		u[1] = 1;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
			{
				x = i - 1;
				break;
			}
			if (i == a.size() - 1)
			{
				x = i;
			}
		}
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (a[i] != b[i])
			{
				y = i + 1;
				break;
			}
			if (i == 0)
			{
				y = i;
			}
		}
		for (int j = 0; j < a.size(); j++)
		{
			u[j] = u[j - 1] * p % w;
			c[j] = (c[j - 1] * p + (a[j] - 'a')) % w;
		}
		for (int j = 0; j < b.size(); j++)
		{
			d[j] = (d[j - 1] * p + (b[j] - 'a')) % w;
		}
		for (int j = 0; j < a.size(); j++)
		{
			for (int k = j; k < a.size(); k++)
			{
				if (j <= x && k >= y && v[(c[k] - c[j - 1] * u[k - j] % w + w) % w] == (d[k] - d[j - 1] * u[k - j] % w + w) % w + 1)
				{
					s++;
				}
			}
		}
		cout << s << "\n";
	}
	return 0;
}
