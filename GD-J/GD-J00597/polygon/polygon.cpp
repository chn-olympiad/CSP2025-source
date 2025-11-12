#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], tr[5005][5005], sum;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n <= 3)
	{
		sort (a + 1, a + n + 1);
		if (a[1] + a[2] + a[3] >= a[3] * 2)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{//n条边组成i边形的方法数（不考虑能否构成） ，可以预处理出杨辉三角（组合数）
		for (int i = 0; i <= 5002; i++)
		{
			tr[i][0] = 1;
		}
		for (int i = 1; i <= 5002; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				tr[i][j] = (tr[i - 1][j - 1] + tr[i - 1][j]) % MOD;
			}
		}
		for (int i = 3; i <= n; i++)
		{
			sum = (sum + tr[n][i]) % MOD;
		}
		cout << sum;
	}
	return 0;
}
