#include <bits/stdc++.h>

using namespace std;

int dp[5005][5005] = {{}};
int ar[5005] = {};

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> ar[i];
	}
	sort(ar,ar + n);
	long long num = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int k = j;k >= 1;k--)
			{
				dp[i][j] = ar[j] + dp[i - 1][j - k];
				if (ar[j] * 2 < dp[i][j])
				{
					//cout << dp[i][j] << ' ' << ar[j] << endl;
					num++;
					num %= 998244353;
				}
			}
		}
	}
	cout << num;
	return 0;
}
