#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, a[maxn], b[maxn];
int cnt;
void f(int k, int m)
{
	int p = 1;
	b[1] = k;
	int j = k;
	while (p && b[1] == k && b[2] != n)
	{
		if (p == m)
		{
			int lsub = 0, lmax = 0;
			for (int i = 1; i <= m; i++)
			{
				lsub += a[b[i]];
				lmax = max(lmax, a[b[i]]);
			}
			if (lsub > lmax * 2) cnt++;
			p--;
		    if (b[p+1] == n)
		    {
		    	p = k;
		    	j = b[p+1];
			}
		}
		else
		{
			p++;
		    b[p] = ++j;
		}
	}
	
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	if (n == 3)
	{
		int sum = a[1] + a[2] + a[3];
		if (sum > 2 * a[3]) cout << 1;
		else cout << 0;
	}
	else
	{
		for (int i = 1; i <= n-2; i++)
		{
			for (int j = 3; j <= n+1-i; j++)
			{
				f(i, j);
			}
		}
		cout << cnt;
	}
}
