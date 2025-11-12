#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[N] = {0};
	int xs[N] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	xs[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		xs[i] = xs[i - 1] ^ a[i];
	}
	int xr1[N] = {0};
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		int f = 1;
		while (i + j < n)
		{
			if (j == 0)
			{
				if ((xs[i] ^ xs[i - 1]) == k)
				{
					f = 0;
					xr1[i] = 0;
					break;
				}
			}
			else
			{
				if ((xs[i + j] ^ xs[i - 1]) == k)
				{
					f = 0;
					xr1[i] = j;
					break;
				}
			}
			j++;
		}
		if (f) xr1[i] = -1;
	}
	int dp[N] = {0};
	dp[n - 1] = (xr1[n - 1] == 0 ? 1 : 0);
	for (int i = n - 2; i >= 0; i--)
	{
		if (xr1[i] == -1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + xr1[i] + 1] + 1, dp[i + 1]);
		}
	}
	cout << dp[0] << endl;
	return 0;
}
