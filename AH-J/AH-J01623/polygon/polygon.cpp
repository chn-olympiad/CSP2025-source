#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int mod = 998244353;
int n, a[5005], dp[5005][5005], f[5005][5005];
int sum[5005];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	if (n <= 3)
	{
		int maxx = 0;
		for (int i = 1; i <= n; i++)
		{
			maxx = max(maxx, a[i]);
		}
		if (sum[n] > 2 * maxx)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i + 2; j <= n; j++)
		{
			if (a[j] > 2 * max(a[i], a[i + 1]) - (a[i] + a[i + 1]))
			{
				f[i][i + 1]++;
			}
	    }
		cout << i << " " << i + 1 << " " << f[i][i + 1] << endl; 
	}
	for (int j = 3; j <= n; j++)
	{
		for (int i = 1; i <= n - j; i++)
		{
			f[i][i + j - 1] = f[i][i + j - 2];
			cout << i << " " << i + j - 1 << " " << f[i][i + j - 1] << endl;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		dp[1][i] = (dp[1][i - 1] + f[1][i - 1]) % mod;
	}
	cout << dp[1][n] % mod;
	return 0;
}
