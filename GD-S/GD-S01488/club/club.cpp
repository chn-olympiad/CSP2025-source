#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, a[3][N], t, ans, b[3][N], cnt[3];
void check(int aa)
{
	if(cnt[aa] <= n/2)
		return;
	sort(b[aa]+1, b[aa]+cnt[aa]+1);
	int p = cnt[aa]-n/2;
	for(int i = 1; i <= p; i++)
		ans -= b[aa][i];
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[0][i] >= a[1][i])
			{
				if(a[0][i] >= a[2][i])
				{
					ans += a[0][i];
					b[0][++cnt[0]] = a[0][i]-max(a[1][i], a[2][i]);
				}
				else
				{
					ans += a[2][i];
					b[2][++cnt[2]] = a[2][i]-a[0][i];
				}
			}
			else
			{
				if(a[2][i] >= a[1][i])
				{
					ans += a[2][i];
					b[2][++cnt[2]] = a[2][i]-a[1][i];
				}
				else
				{
					ans += a[1][i];
					b[1][++cnt[1]] = a[1][i]-max(a[2][i], a[0][i]);
				}
			}
		}
		check(0);
		check(1);
		check(2);
		printf("%d\n", ans);
	}
	return 0;
}
