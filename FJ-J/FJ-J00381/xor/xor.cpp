#include<bits/stdc++.h>
using namespace std;
int yh(int x, int y)
{
	int ans = 0, i = 1;
	while (x > 0 || y > 0)
	{
		if (x % 2 != y % 2)
			ans += i;
		x /= 2;
		y /= 2;
		i *= 2;
	}
	return ans;
}
int n, k, a[500005], qzh[500005], yhqz[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		qzh[i] = yh(qzh[i - 1], a[i]);
	}
	for (int i = 1; i <= n; i++)
		yhqz[i] = yh(qzh[i], k);
	int lt = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= lt; j--) 
		{
			if (yhqz[i] == qzh[j])
			{
				ans++;
				lt = i;
			}
		}
	}
	cout << ans;
	return 0;
}
