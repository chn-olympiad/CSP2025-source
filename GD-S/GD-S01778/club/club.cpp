#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+7;
int a[N][3];
int c0,c1,c2;
int n;
int cnt=0;
int p[N];
int g[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		c0=c1=c2=0,cnt=0;
		int res=0;
		memset(g,-1,sizeof(g));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int kk=max(a[i][0],max(a[i][1],a[i][2]));
			res+=kk;
			int cnt=0;
			int c[5];
			if(kk==a[i][0])
			c[++cnt]=0;
			if(kk==a[i][1])
			c[++cnt]=1;
			if(kk==a[i][2])
			c[++cnt]=2;
			int id;
			int mn=1e9;
			for(int j=1;j<=cnt;j++)
			{
				if(c[j]==0)
				{
					if(c0<mn)
					{
						mn=c0;
						id=0;
					}
				}
				if(c[j]==1)
				{
					if(c1<mn)
					{
						mn=c1;
						id=1;
					}
				}
				if(c[j]==2)
				{
					if(c2<mn)
					{
						mn=c2;
						id=2;
					}
				}
			}
			if(id==0)
			c0++;
			if(id==1)
			c1++;
			if(id==2)
			c2++;
			g[i]=id;
		}
		if(max(c1,max(c0,c2))<=n/2)
		{
			printf("%d\n",res);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(c0>n/2&&g[i]==0)
			p[++cnt]=a[i][0]-max(a[i][1],a[i][2]);
			if(c1>n/2&&g[i]==1)
			p[++cnt]=a[i][1]-max(a[i][0],a[i][2]);
			if(c2>n/2&&g[i]==2)
			p[++cnt]=a[i][2]-max(a[i][0],a[i][1]);
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=max(c0,max(c1,c2))-(n/2);i++)
		res-=p[i];
		printf("%d\n",res);
	}
	return 0;
}


