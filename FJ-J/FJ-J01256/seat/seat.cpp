#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
}z[200];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int n,m,k=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&z[i].a);
		z[i].b=i;
	}
	sort(z+1,z+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(k==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(z[(i-1)*n+j].b==1)
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
				if(z[(i-1)*n+n-j+1].b==1)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		k=-k;
	}
		
}