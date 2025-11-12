#include <bits/stdc++.h>
using namespace std;


const int N = 1e5;
long long n, t, a[N][5], mn[5], num[5], ans, mnid[5];

int main()
{
	#ifdef LOCAL
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	#endif
	cin >> t;
	while(t --)
	{
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			if(i == 1)
			{
				for(int j = 1; j <= 3; j ++)
				{
					mn[j] = 0;
					num[j] = 0;
					mnnum[j] = 0;
				}
			}
			for(int j = 1; j <= n; j ++)
			{
				cin >> a[i][j];
			}
			if(a[i][1] > a[i][2] && a[i][1]> a[i][3])
			{
				if(num[1] <= n / 2)
				{
					ans += a[i][1];
					if(mn[1] > min(a[i][1] - a[i][2], a[i][1] - a[i][3]))
					{
						mn[1] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
						mnid = i;
					}
				}
				else if(mn[1] > min(a[i][1] - a[i][2], a[i][1] - a[i][3]))
				{
					ans += a[i][1];
					
				}
			}
		}
	}
}
