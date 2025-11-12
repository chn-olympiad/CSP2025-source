#include <bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,c,b=100000,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int  j=1;j<=m;j++)
		{
			if(a[i][j]<b)
			{
			  a[i][j]==b;
			}
			if(a[i][j]>c)
			{
			  a[i][j]==c;
			}
			cout<<a[1][1];
		}
	}
	
	
	return 0;
}
