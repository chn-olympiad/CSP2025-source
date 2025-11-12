#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,b[114514],c,ans,cnt,e;
struct man
{
	int v[5],m1,m2,v1,v2;
	bool operator<(const man &x)const
	{
		return v1-v2<x.v1-x.v2;
	}
}a[114514],d[114514];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		b[1]=0,b[2]=0,b[3]=0;
		ans=0;
		c=0;
		cnt=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].v[1],&a[i].v[2],&a[i].v[3]);
			a[i].m1=0,a[i].m2=0,a[i].v1=0,a[i].v2=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i].v[j]>=a[i].v1)
				{
					a[i].v1=a[i].v[j];
					a[i].m1=j;
				}
			}
			for(int j=1;j<=3;j++)
			{
				if(j!=a[i].m1)
				{
					if(a[i].v[j]>=a[i].v2)
					{
						a[i].v2=a[i].v[j];
						a[i].m2=j;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			b[a[i].m1]++;
			ans+=a[i].v1;
		}
		for(int i=1;i<=3;i++)
		{
			if(b[i]>n/2)
			{
				c=i;
				e=b[i]-n/2;
				break;
			}
		}
		if(c==0)
		{
			printf("%lld\n",ans);
			continue;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].m1==c)
				{
					cnt++;
					d[cnt]=a[i];
				}
			}
			sort(d+1,d+1+cnt);
			for(int i=1;i<=e;i++)
			{
				ans-=(d[i].v1-d[i].v2);
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}
