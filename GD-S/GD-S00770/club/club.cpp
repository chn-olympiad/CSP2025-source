#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100010][4],tmp[100010];
int mx[100010],sc[100010];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= 3 ; j++)
			{
				cin >> a[i][j];
				tmp[j] = a[i][j];
			}
			sort(tmp + 1,tmp + 4);
			for (int j = 1 ; j <= 3 ; j++)
			{
				if (a[i][j] == tmp[3])
				{
					mx[i] = j;
				}
			}
			for (int j = 1 ; j <= 3 ; j++)
			{
				if (a[i][j] == tmp[2] && j != mx[i])
				{
					sc[i] = j;
				}
			}
		}
		int ans = 0;
		tmp[1] = tmp[2] = tmp[3] = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			ans += a[i][mx[i]];
			tmp[mx[i]]++;
		} 
		int cnt = 0;
		int MX = max(tmp[1],max(tmp[2],tmp[3]));
		if (MX > n / 2)
		{
			int k;
			for (k = 1 ; k <= 3 ; k++)
			{
				if (tmp[k] == MX)
				{
					break;
				}
			}
			for (int i = 1 ; i <= n ; i++)
			{
				if (mx[i] == k)
				{
					cnt++;
					tmp[cnt] = a[i][mx[i]] - a[i][sc[i]];
				}
			}
			sort(tmp + 1,tmp + cnt + 1);
			for (int i = 1 ; i <= MX - n / 2 ; i++)
			{
				ans -= tmp[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
