#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], ans;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
	{
		long long sum = 0;
		for (int j = i; j <= n; j ++)
		{
			sum ^= a[j];
			if (sum == k)
			{
				i = j;
				ans ++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
