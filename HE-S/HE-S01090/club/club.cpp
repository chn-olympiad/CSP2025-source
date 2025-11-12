#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	for (int ti=1;ti<=t;ti++)
	{
		int n;
		cin >>n;
		long long a[n+1][4];
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin >>a[i][j];
			}
		}
		long long ma=0;
		for (int i=1;i<=3;i++)
		{
			for (int j=1;j<=3;j++)
			{
				if (j==i)
				{
					continue;
				}
				if (a[1][i]+a[2][j]>ma)
				{
					ma=a[1][i]+a[2][j];
				}
			}
		}
		cout <<ma <<endl;
	}
	return 0;
}
