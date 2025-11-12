#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],maxx=-1,bh=1,now=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",a+i);
		if(a[i]>maxx)
		{
			maxx=a[i];
			bh=i;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				now++;
				if(now==bh)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				now++;
				if(now==bh)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
98 97
99 100
*/
