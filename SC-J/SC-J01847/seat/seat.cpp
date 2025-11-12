#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b);
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[11][11],x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(i==1&&j==1)
			{
				x=a[i][j];
			}
		}
		
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x==a[i][j])
			{
				cout<<i<<j;
				return 0;
			}
		}
		
	}
	return 0;
 }