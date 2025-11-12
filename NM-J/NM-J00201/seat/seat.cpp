#include <bits/stdc++.h>
using namespace std;
int a[13][13],b[111];
int main()
{
	int i,j;
  	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for (i=1;i<=n*m;i++)
	{
		cin>>s;
		b[i]=s;
	}
	int y=b[1];
	sort(b,b+i);
	int k=n*m;
	for (i=1;i<=n;i++)
	{
		if (i%2==1)
		{
			for (j=1;j<=m;j++)
			{
				a[i][j]=b[k];
				k--;
			}
		}
		else if (i%2==0)
		{
			for (j=m;j>=1;j--)
			{
				a[i][j]=b[k];
				k--;	
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (y==a[i][j])
			{
				cout<<i<<' '<<j;
				return 0; 
			}
		}
	}
	return 0;
}
