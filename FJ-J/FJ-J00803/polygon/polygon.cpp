#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long mod = 998244353;
long long n, a[N], sum[N], ans, f[N][N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool b = true;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			b = false;
		}
		sum[i] = sum[i-1] + a[i];
	}
	if (b)
	{
		for (int i = 3;i <= n;i++)
		{
			long long cnt = 1;
			for (long long j = 1;j <= i;i++)
			{
				cnt = (cnt * (n-j+1) / j) % mod;
			}
			ans = (ans + cnt) % mod;
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 3;i <= n;i++)
	{
		for (int j = 3;j <= i;j++)
		{
			long long cnt = 0;
			for (int k = 1;k <= i;k++)
			{
				if (sum[i] - sum[k] > 2*a[i])
				{
					cnt++;
				}
			}
			f[j][i] = (f[j][i-1] + cnt) % mod;
		}
	}
	for (int i = 3;i <= n;i++)
	{
		ans = (ans + f[i][n]) % mod;
	}
	cout << ans;
	return 0;
}
