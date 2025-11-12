#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],b,bg=-10086;
int c[1005],d,e=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	for(int i=1;i<=m*n;i++)
	{
		for(int i=1;i<=m*n;i++)
		{
			if(a[i]>bg && a[i] !=-1)
			{
				bg=a[i];
				d=i;
			}
		}
		c[i]=bg;
		a[d]=-1;
		bg=0;
	}
	for(int i=1;i<=m;i++)
	{
		if((i % 2) != 0)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[e] == b)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				else
				{
					e++;
				}
			}	
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(c[e] == b)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				else
				{
					e++;
				}
			}
		}
		
	}
	return 0;
}
