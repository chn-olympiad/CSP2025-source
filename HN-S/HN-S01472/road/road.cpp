#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,u[20000],mc,nc,fc,mci;
struct road
{
	long long u;
	long long v;
	long long w;
}r[2000000];
struct city
{
	int isOK;
	long long c;
	long long a[2000000];
}c1[20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c1[i].c);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&c1[i].a[j]);
		}
	}
	u[1]=1;
	nc=1;
	for(int i=1;i<n;i++)
	{
		mci=0;
		fc=10000000000;
		for(int j=2;j<=n;j++)
		{
			if(u[j]==0)
			{
				for(int k1=1;k1<=m;k1++)
				{
					if(r[k1].u==nc&&r[k1].v==j||r[k1].u==j&&r[k1].v==nc)
					{
						if(r[k1].w<fc)
						{
							fc=r[k1].w;
							mc=j;
							mci=0;
//							printf("try:%d %d cost:%d new:%d\n",nc,mc,fc,mci);
						}
					}
				}
				for(int k1=1;k1<=k;k1++)
				{
					if(c1[k1].isOK==1)
					{
						if(c1[k1].a[nc]+c1[k1].a[j]<fc)
						{
							fc=c1[k1].a[nc]+c1[k1].a[j];
							mc=j;
							mci=0;
//							printf("try:%d %d cost:%d new:%d\n",nc,mc,fc,mci);
						}
					}
					else
					{
						if(c1[k1].c+c1[k1].a[nc]+c1[k1].a[j]<=fc)
						{
							fc=c1[k1].c+c1[k1].a[nc]+c1[k1].a[j];
							mc=j;
							mci=k1;
//							printf("try:%d %d cost:%d new:%d\n",nc,mc,fc,mci);
						}
					}
				}
			}
		}
//		printf("true:%d %d cost:%d new:%d\n",nc,mc,fc,mci);
		ans+=fc;
		nc=mc;
		u[mc]=1;
		c1[mci].isOK=1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
