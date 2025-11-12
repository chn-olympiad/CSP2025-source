#include <bits/stdc++.h>
using namespace std;

int ttt, n, a[100005][5], b[100005], sum[100005], s1, s2, s3, cnt, ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &ttt);
	while (ttt--)
	{
		scanf("%d", &n);
		s1 = s2 = s3 = cnt = ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			{
				s1++;
				ans += a[i][1];
				b[i] = 1;
			}
			else if (a[i][2] >= a[i][3] && a[i][2] >= a[i][1])
			{
				s2++;
				ans += a[i][2];
				b[i] = 2;
			}
			else
			{
				s3++;
				ans += a[i][3];
				b[i] = 3;
			}
		}
		if (s1 * 2 > n)
		{
			for (int i = 1; i <= n; i++)
			{
				if (b[i] == 1)
				{
					sum[++cnt] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
				}
			}
			sort(sum + 1, sum + cnt + 1);
			for (int i = 1; i <= s1 - (n / 2); i++)
			{
				ans -= sum[i];
			}
		}
		if (s2 * 2 > n)
		{
			for (int i = 1; i <= n; i++)
			{
				if (b[i] == 2)
				{
					sum[++cnt] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
				}
			}
			sort(sum + 1, sum + cnt + 1);
			for (int i = 1; i <= s2 - (n / 2); i++)
			{
				ans -= sum[i];
			}
		}
		if (s3 * 2 > n)
		{
			for (int i = 1; i <= n; i++)
			{
				if (b[i] == 3)
				{
					sum[++cnt] = min(a[i][3] - a[i][2], a[i][3] - a[i][1]);
				}
			}
			sort(sum + 1, sum + cnt + 1);
			for (int i = 1; i <= s3 - (n / 2); i++)
			{
				ans -= sum[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
