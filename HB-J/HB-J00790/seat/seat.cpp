#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[15][15],c,d,sum=0,v;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int x=a[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i;k<=n;k++)
			{
				if(k!=i)
				{
					for(int w=1;w<=m;w++)
					{
						if(a[i][j]<a[k][w])
						{
							swap(a[i][j],a[k][w]);
						}
					}				
				}
				else{
				for(int w=j;w<=m;w++)
				{
					if(a[i][j]<a[k][w])
					{
						swap(a[i][j],a[k][w]);
					}
				}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum++;
			if(sum%n==0)
			{
				v=n;
			}
			else
			{
				v=sum%n;
			}
			if((sum/n+1)%2==0)
			{
				d=n+1-v;
			}
			else
			{
				d=v;
			}
			if(sum%n==0)
			{
				c=sum/n;
			}
			else
			{
				c=sum/n+1;
			}
			b[d][c]=a[i][j];
			if(x==b[d][c])
			{
				cout<<c<<' '<<d;
				break;
			}
		}
	}
	return 0;
}
