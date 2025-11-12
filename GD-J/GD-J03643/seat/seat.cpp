#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,lspoint=0,lsflag=0;
struct node
{
	int point,id;
}a[N];

int cmp(node a,node b)
{
	if(a.point>b.point)
	{
		return 1;
	}
	if(a.point==b.point&&a.id<b.id)
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].point);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(lsflag)
		{
			break;
		}
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[++lspoint].id==1)
				{
					printf("%d %d",i,j);
					lsflag=1;
					break;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[++lspoint].id==1)
				{
					printf("%d %d",i,j);
					lsflag=1;
					break;
				}
			}
		}
	}
	return 0;
}
