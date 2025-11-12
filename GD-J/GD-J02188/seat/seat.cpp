#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct node
{
	int k,xh;
}stu[1005];
bool cmp(node x,node y){return x.k>y.k;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,a;i<=n*m;i++)
	{
		scanf("%d",&a);
		stu[++cnt].k=a;
		stu[cnt].xh=i;
	}
	sort(stu+1,stu+1+cnt,cmp);cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				if(stu[++cnt].xh==1)
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
				if(stu[++cnt].xh==1)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
