#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in",'r',stdin);
	freopen("club.out",'w',stdout);
	int t,n,a[1005][1005][3],maxn = -1987,ans = 0;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		ans = 0;
		cin >> n;
		for (int j = 1;j <= n;j++)
		{
			maxn = -1987;
			for (int k = 1;k <= 3;k++)
			{
				cin >> a[i][j][k];	
				maxn = max(maxn,a[i][j][k]);
			}
			ans += maxn;	
		}
		cout << ans;	
	}	
 	return 0;
}
