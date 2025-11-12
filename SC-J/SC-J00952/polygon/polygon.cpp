#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;
int a[5010], sum[5010];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	sum[0] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i >= 3)
			for (int j = a[i] + 1; j <= 5001; j++)
				ans = (ans + sum[j]) % p;
		for (int j = 5001; j >= 0; j--)
		{
			if (j + a[i] >= 5001)
				sum[5001] = (sum[5001] + sum[j]) % p;
			else sum[j+a[i]] = (sum[j+a[i]] + sum[j]) % p;
		}
	}
	cout << ans << endl;
	return 0;
}