#include<bits/stdc++.h>
using namespace std;
int main()
{
	preopen("seat.in","r",seatin)
	preopen("seat.out","w",seatout)
	int n,m,a[110],x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		x=a[1];
	}
	int c,r;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[j+1]<a[j])
			{
				int d=a[j+1];
				a[j+1]=a[j];
				a[j]=d;
			}
		}
	}
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==x)
		{
			int y=i;
			if(y%n==0)
			{
				c=y/n;
			}
			else;
			{
				c=y/n+1;
			}
		}
	}
	cout<<c;
	return 0;
}
