#include<bits/stdc++.h>
using namespace std;
int a[1010],b[110][110],n,m,r,ii;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[++ii];
				if(a[ii]==r)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[j][i]=a[++ii];
				if(a[ii]==r)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
