#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, c[505], num[505];
string s;
long long f[505][505], sum[505][505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
		num[i] = num[i-1];
		if (c[i] == 0)
		{
			num[i]++;
		}
	}
	sort(c+1,c+n+1);
	for (int i = 1;i <= n;i++)
	{
		if (s[0] == 1 && c[i] != 0)
		{
			f[1][1]++;
		}
	}
	for (int i = 2;i <= n;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			if (j + num[i] > i)
			{
				continue;
			}
			long long cnt = 0;
			while (c[i-cnt] == 0)
			{
				cnt++;
			}
			if (cnt > 0)
			{
				f[i][j] += f[i-cnt][j];
			}
			else
			{
				cnt++;
				while (c[i-cnt] == 0)
				{
					cnt++;
				}
				int ctn = 0;
				for (int k = f[1][1]-j+1;k <= f[1][1];k++)
				{
					if (c[k] > num[i])
					{
						ctn++;
					}
				}
				f[i][j] += f[i-cnt][j-1]*ctn;
			}
			sum[i][j] = f[i][j] + sum[i][j-1];
		}
	}
	cout << sum[n][n-num[n]] - sum[n][m-1];
	return 0;
}
