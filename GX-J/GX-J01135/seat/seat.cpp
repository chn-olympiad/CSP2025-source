#include <bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int count=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int xm=a[1];
	sort(a+1,a+n*m+1);
	for(int i=m;i>=1;i--)
	{
		if(i%2==0)
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[count];
				count++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[j][i]=a[count];
				count++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==xm) 
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
