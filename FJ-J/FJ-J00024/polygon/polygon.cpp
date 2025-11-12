#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[1005];
long long ans = 0;
long long C[1005][1005];
bool p[105];
void dfs(int x)
{
	if (x == n + 1)
	{
		long long sum = 0;
		long long maxx = -1;
		long long num = 0;
		for (int i = 1;i <= n;i++)
		{
			if (p[i])
			{
				maxx = max(maxx,a[i]);
				sum += a[i];
				num++;
			}
		}
		if (num < 3)
		{
			return ;
		}
		if (sum > maxx * 2)
		{
			ans = (ans + 1) % 998244353; 
		}
		return ;
	}
	p[x] = 1;
	dfs(x + 1);
	p[x] = 0;
	dfs(x + 1);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n > 21)
	{
		for (int i = 1;i <= n;i++)
		{
			C[i][0] = C[0][i] = 1;
			cin >> a[i];
		}
		C[1][1] = 1;
		for (int i = 2;i <= n;i++)
		{
			for (int j = 1;j <= i;j++)
			{
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		long long sum = 0;
		for (int i = 3;i <= n;i++)
		{
			sum = (sum + C[n][i]) % 998244353;
		}
		cout << sum;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ans % 998244353;
	return 0;
}
