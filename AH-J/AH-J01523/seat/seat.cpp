#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,ans[20][20];
struct scj
{
	int cj,id;
}a[200];
int cmp(scj x,scj y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].cj);
		a[i].id=i;
	}
	int k=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				ans[j][i]=a[++k].id;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				ans[j][i]=a[++k].id;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==1)
			{
				printf("%d %d",j,i);
				break;
			}
		}
	}
	return 0;
}
