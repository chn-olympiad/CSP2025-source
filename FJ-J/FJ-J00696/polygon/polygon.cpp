#include<bits/stdc++.h>
using namespace std;
long long ans=24,n,a[100000],ma,num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int m=n;
	while(m>=3)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=m;j++)
			{
				break;
			}
			if (num>ma)
				ans++;
		}
		m--;
	}
	cout << ans;
	return 0;
}
