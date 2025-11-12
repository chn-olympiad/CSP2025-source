#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[4], b[4][N], cnt[4], ans; 
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int q = 1;q <= n;q++)
		{
			cin >> a[1] >> a[2] >> a[3];
			for (int i = 1;i <= n;i++)
			{
				if (a[i] >= a[i % 3 + 1] && a[i] >= a[(i + 1) % 3 + 1])
				{
					b[i][++cnt[i]] = a[i] - max(a[i % 3 + 1], a[(i + 1) % 3 + 1]);
					ans += a[i];
					break;
				} 
			}
		}
		for (int q = 1;q <= 3;q++)
		{
			sort(b[q] + 1, b[q] + cnt[q] + 1);
			for (int i = 1;i <= cnt[q] - n / 2;i++)
			{
				ans -= b[q][i];
			}
		}
		cout << ans << "\n";
		ans = cnt[1] = cnt[2] = cnt[3] = 0;
	}
	return 0;
}
