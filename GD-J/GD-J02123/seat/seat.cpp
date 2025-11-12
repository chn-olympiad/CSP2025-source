#include <bits/stdc++.h>
using namespace std;
int n,m,seat[15][15],a[105],t,sum,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for (int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+sum+1);
	reverse(a+1,a+sum+1);
	t=1;
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				seat[i][j]=a[t];
				t++;
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				seat[i][j]=a[t];
				t++;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
		    if (seat[i][j]==r)
		    {
		    	cout<<i<<" "<<j;
		    	break;
			}
		}
	}
	return 0;
}
