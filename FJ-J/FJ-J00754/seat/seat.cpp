#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
		cin >> a[i];
	int target = a[1];
	sort(a+1,a+n*m+1);
	int x = lower_bound(a+1,a+n*m+1,target) - a;
	x = n*m-x+1;
	int cnt = 0;
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1)		
		{
			for (int j = 1;j <= n;j++)
			{
				cnt++;
				if (cnt == x)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		if (i % 2 == 0)
		{
			for (int j = n;j >= 1;j--)
			{
				cnt++;
				if (cnt == x)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		
	}
	return 0;
}
