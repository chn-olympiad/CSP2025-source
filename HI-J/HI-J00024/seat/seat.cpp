#include<bits/stdc++.h>
using namespace std;
int a[13][13],b[105];
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&b[i]);
	int c=b[1];
	for(int i=1;i<n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(b[j]>b[i])
			{
				d=b[j];b[j]=b[i];b[i]=d;
			}
		}
	}
	d=1;
	bool x=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				a[i][j]=b[d++];
				if(a[i][j]==c)
				{
					printf("%d %d",j,i);
					x=1;
					break;
				}
			}
			if(x==1)break;
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				a[i][j]=b[d++];
				if(a[i][j]==c)
				{
					printf("%d %d",j,i);
					x=1;
					break;
				}
			}
			if(x==1)break;
		}
	}
	return 0;
}
