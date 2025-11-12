#include <bits/stdc++.h>
using namespace std;
long long t , n;
int a[10005][10005] , maxx = 0 , sum = 0 , x , y , z;
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n;
		sum = 0;
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= 3;k++)
			{
				cin >> a[j][k];
			}
			maxx = max(a[j][1] , max(a[j][2] , a[j][3]));
			sum += maxx;
			if(maxx == a[j][1])
			{
				x++;
				if (x > (n / 2))
				{
					sum -= maxx;
					sum += max(a[j][3] ,a[j][2]);
				}
			}
			else if (maxx == a[j][2])
			{
				y++;
				if (y > (n / 2))
				{
					sum -= maxx;
					sum += max(a[j][1] , a[j][3]);
				}
			}
			else
			{
				z++;
				if (z > (n / 2))
				{
					sum -= maxx;
					sum += max(a[j][1] , a[j][2]);
				}
			}
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
