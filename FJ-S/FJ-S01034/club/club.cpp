#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
int n,a[N][3],b[N],c[N],x,y,z,t,ans,ct;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=ct=x=y=z=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int c=max({a[i][0],a[i][1],a[i][2]});
			if(c==a[i][0])b[i]=0,x++,ans+=a[i][0];
			else if(c==a[i][1])b[i]=1,y++,ans+=a[i][1];
			else if(c==a[i][2])b[i]=2,z++,ans+=a[i][2];
		}
		int u=0;
		if(x>n/2)
		{
			u=x;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==0)
				c[++ct]=a[i][0]-max(a[i][1],a[i][2]);
			}
		}
		if(y>n/2)
		{
			u=y;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==1)
				c[++ct]=a[i][1]-max(a[i][0],a[i][2]);
			}
		}
		if(z>n/2)
		{
			u=z;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==2)
				c[++ct]=a[i][2]-max(a[i][1],a[i][0]);
			}
		}
		sort(c+1,c+1+ct);
		for(int i=1;u>n/2;i++,u--)
		ans-=c[i];
		printf("%d\n",ans);
	}
}
