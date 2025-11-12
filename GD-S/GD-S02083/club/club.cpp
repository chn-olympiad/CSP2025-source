#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],ans,cnt[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 1;i <= n;i++)
		{
			if (cnt[1] <= n / 2 && a[i][1] == max(a[i][1],max(a[i][2],a[i][3])))
			{
				ans += a[i][1];
				cnt[1]++;
			}
			else if (cnt[2] <= n / 2 && a[i][2] == max(a[i][1],max(a[i][2],a[i][3])))
			{
				ans += a[i][2];
				cnt[2]++;
			}
			else
			{
				ans += a[i][3];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
