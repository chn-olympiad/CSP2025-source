#include<bits/stdc++.h>
using namespace std;
int n,a[5005]{0},ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 3;j <= n;j++)
		{
			int sum = 0,maxn = 0;
			for (int k = i;k <= j;k++)
			{
				maxn = max(maxn,a[k]);
				sum += a[k];
			}
			if (sum > 2 * maxn)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
