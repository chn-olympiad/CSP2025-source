#include <bits/stdc++.h>
using namespace std;

int a[500005];

struct S
{
	int b, e;
}d[500005];

bool cmp(S x, S y)
{
	return x.e < y.e;	
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int res = a[i];
			for (int p = i + 1; p <= j; p++)
			{
				res = res ^ a[p];
			}
			if (res == k) 
			{
				cur ++;
				d[cur].b = i;
				d[cur].e = j;
			}
		}
	}

	sort(d + 1, d + cur + 1, cmp);
	
	int ans = 0, minn = 1e9, last = 0;
	for (int i = 1; i <= cur; i++)
	{
		if (d[i].b > last)
		{
			last = d[i].e;
			ans ++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
