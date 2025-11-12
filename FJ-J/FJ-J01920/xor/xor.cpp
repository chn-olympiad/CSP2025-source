#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N], st[N][N], f[N], k, sum[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (n <= 1004)
	{
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			st[i][i] = a[i];
			if (a[i] == k) sum[i] = i;
		}
		for (int len = 1;len < n;len++)
		{
			for (int i = 1;i <= n;i++)
			{
				if (i + len > n) break;
				st[i][i + len] = (st[i][i + len - 1] ^ a[i + len]);
				if (st[i][i + len] == k && sum[i + len] == 0)
					sum[i + len] = i;
			}
		}
		f[1] = (a[1] == k);
		for (int i = 1;i <= n;i++)
		{
			f[i] = f[i - 1];
			if (sum[i])
				f[i] = max(f[i], f[sum[i] - 1] + 1);
		}
		cout << f[n];
	}
	return 0;
}
