#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans, sum[500005], flag = 1;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		if (a[i] > 1)
		{
			flag = 0;
		}
	}
	if (flag)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += a[i];
			if (a[i] % 2 == k)
			{
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	int last = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; i - j >= last; j++)
		{
			if ((sum[i] ^ sum[i - j]) == k)
			{
				cout << i - j + 1 << " " << i << " ";
				ans++;
				last = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
