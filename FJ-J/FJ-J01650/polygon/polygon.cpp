#include <bits/stdc++.h>
using namespace std;
int a[1000000],vis[1000000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	if(n == 3)
	{
		int sum = 0;
		int maxn = -1;
		for (int i = 1 ; i <= n ; i++)
		{
			maxn = max(maxn,a[i]);
			sum += a[i];
		}
		if(maxn * 2 >= sum)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
	long long ans = 0;
	for (int i = n ; i >= 1 ; i--)
	{
		ans += (1 + n) * n / 2;
		ans = ans % 998244353;
	}
	cout << ans;
	return 0;
}
