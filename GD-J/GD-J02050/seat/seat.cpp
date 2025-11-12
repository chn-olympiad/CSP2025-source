#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum;
int a[105];
int sx;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	sum=n*m;
	for(int i=1;i<=sum;i++) scanf("%d",&a[i]);
	sx=a[1];
	sort(a+1,a+1+sum);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[sum]==sx)
				{
					printf("%d %d",i,j);
					return 0;
				}
				sum--;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[sum]==sx)
				{
					printf("%d %d",i,j);
					return 0;
				}
				sum--;
			}
		}
	}
}
