#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=1,c1;
	for (int i=1;i<=n*m;i++)
	{
		if (i==1) cin>>c1;
		else
		{
			int c2;
			cin>>c2;
			if (c2>c1) s++;
		}
	}
	int cnt=0;
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				cnt++;
				if (cnt==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				cnt++;
				if (cnt==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		
	}
	return 0;
}
