#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000][1000],c[1000],d=1;
int x=1,y=1;
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int g;
	g=m*n;
	int f=a[1]
	sort(a+1,a+1+g);
	for(int i=n*m;i>=1;i--)
	{
		c[i]=a[d];
		d++;
	}
	for(int i=1;i<=n;i++)
	{
		b[i][1]=c[i];
	}
	for(int j=2;j<=m;j++)
	{
		y++;
		if(j%2!=0)
		{
			for(int i=1;i<=n;i++)
			{
				x=1;
				b[i][j]=c[y*(j-1)+x];
				x++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				x=1;
				b[i][j]=c[y*(j-1)+x];
				x++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==f)
			{
				cout<<i<<" "<<j;
				
			}
		}
	}
	return 0;
}
