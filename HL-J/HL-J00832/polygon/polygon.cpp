#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int maxn = -1, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > maxn)
		{
			maxn = a[i];
		}
		sum += a[i];
	}
	const int maxn_2 = maxn * 2;
	if ((sum > maxn_2) && (n >= 3))
		ans++;
	cout << ans % 998;
	return 0;
}