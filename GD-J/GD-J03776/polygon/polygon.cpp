#include <bits/stdc++.h>

using namespace std;

int a[5010];

int main(void)
{
	freopen("polygon.in", "w", stdin);
	freopen("polygon.out", "r", stdout);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 3; j <= n - i; j++)
		{
			int sum = 0;
			int maxn = 0;
			for (int k = 0; k < j; k++)
			{
				sum += a[k];
				maxn = max(maxn, a[k]);
			}
			if (sum > maxn * 2)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
