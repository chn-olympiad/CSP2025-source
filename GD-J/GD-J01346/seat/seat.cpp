#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[205],d[205];
int f[205][205];
int sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++)
	{
		scanf("%d",&a[i]);
		d[i]=i;
	}
	sum=a[1];
	for(int i=1; i<=n*m; i++)
	{
		for(int j=i+1; j<=n*m; j++)
		{
			if(a[j]>a[i])
			{
				swap(a[i],a[j]);
				swap(d[i],d[j]);
			}
		}
	}
	int x=1,y=1,s=0,t=2;
	while(a[++s]!=sum)
	{
		if(t==1)
		{
			if(y==1)
			{
				x++;
				t=2;
			}
			else
			{
				y--;
			}
		}
		else
		{
			if(y==n)
			{
				x++;
				t=1;
			}
			else
			{
				y++;
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
}
