#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 5010;
int n, a[N], b[N], cnt, ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt += a[i];
	}
	sort(a + 1, a + n + 1);
	if (cnt <= a[n] * 2)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			cnt = 0;
			for (int k = j; k <= n; k++)
			{
				cnt += a[k];
				if (cnt > a[k] * 2)
				{
					ans += n - k + 1;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
