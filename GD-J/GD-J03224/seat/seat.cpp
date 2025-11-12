#include <bits/stdc++.h>
using namespace std;
int n,m,a[20][20],ans=1,lie,hang;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			if(a[i][j]>a[1][1])
			{
				ans++;
			}
		}
	}
	lie=ans/n;
	if(ans%n>=1) lie++;
	if(lie%2==1)
	{
		if(ans%n==0)
		{
			hang=n;
		}
		else
		{
			hang=ans%n;
		}
	}
	else
	{
		if(ans%n==0)
		{
			hang=1;
		}
		else
		{
			hang=n-ans%n+1;
		}
	}
	cout << lie <<' '<< hang;
	return 0;
}
