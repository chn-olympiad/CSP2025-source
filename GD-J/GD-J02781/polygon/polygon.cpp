#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005],f[5005],maxx = -1;
long long mod = 998244353,ans;
void dfs(int x)
{
	if (x == n + 1)
	{
		int cnt = 0,sum = 0,maxp = -1;
		for (int i = 1;i <= n;i++)
		{
			if (f[i])
			{
				cnt++;
				sum += a[i];
				maxp = max(maxp,a[i]);
			}
		}
		if ((cnt >= 3) && (sum > (maxp * 2)))
		{
			ans = (ans + 1) % mod;
		}
		return;
	}
	f[x] = 0;
	dfs(x + 1);
	f[x] = 1;
	dfs(x + 1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{	
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	maxx = a[n];
	if (maxx == 1)
	{
		ans = 1;
		for (int i = 1;i <= n;i++)
		{
			ans = ans * 2 % mod;
		}
		ans = (ans - n + mod) % mod;
		ans = (ans - 1 + mod) % mod;
		ans = (ans - ((long long)n * (n - 1) / 2) + mod + mod) % mod;
		cout << ans;
		return 0;
	}
	else if (maxx <= 10 && n == 3)
	{
		if ((a[1] + a[2] + a[3]) > (a[3] * 2))
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	else
	{
		dfs(1);
		cout << ans;
		return 0;
	}
}
