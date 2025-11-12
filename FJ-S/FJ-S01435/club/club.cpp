#include <bits/stdc++.h>
using namespace std;
const int INF = 100000 + 10;
int a[INF][10];
int qwe[INF], asd[INF], zxc[INF];
int main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n;
		int ans;
		int cnt_1, cnt_2, cnt_3;
		cnt_1 = cnt_2 = cnt_3 = ans = 0;
		scanf("%d", &n);
		int n_half = n / 2;
		for (int i = 1 ; i <= n + 10 ; i ++)
		{
			for (int j = 1 ; j <= 3 ; j ++)
			{
				a[i][j] = 0;
			}
		}
		for (int i = 1 ; i <= n ; i ++)
		{
			for (int j = 1 ; j <= 3 ; j ++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1 ; i <= n ; i ++)
		{
			int maxx = -1, cnt;
			for (int j = 1 ; j <= 3 ; j ++)
			{
				if (maxx <= a[i][j])
				{
					maxx = a[i][j];
					cnt = j;
				}
			}
			if (cnt == 1)
			{
				cnt_1 ++;
				qwe[cnt_1] = maxx;
			}
			if (cnt == 2)
			{
				cnt_2 ++;
				asd[cnt_2] = maxx;
			}
			if (cnt == 3)
			{
				cnt_3 ++;
				zxc[cnt_3] = maxx;
			}
			ans += maxx;
		}
		if (cnt_1 <= n_half && cnt_2 <= n_half && cnt_3 <= n_half)
		{
			printf("%d\n", ans);
			continue;
		}
		else if (cnt_1 > n_half && cnt_2 <= n_half && cnt_3 <= n_half)
		{
			for (int i = 1 ; i <= cnt_1 ; i ++)
			{
				printf("%d ", qwe[i]);
			}
			printf("\n");
			for (int i = 1 ; i <= cnt_2 ; i ++)
			{
				printf("%d ", asd[i]);
			}
			printf("\n");
			for (int i = 1 ; i <= cnt_3 ; i ++)
			{
				printf("%d ", zxc[i]);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
