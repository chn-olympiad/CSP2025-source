#include<bits/stdc++.h>
using namespace std;
#define int long long
struct xy
{
	int x,y,z;
}a[114514],b[114514],c[114514],d[114514];
int n,t;
inline bool cmp1(xy x,xy y)
{
	return min(x.x-x.y,x.x-x.z)<min(y.x-y.y,y.x-y.z);
}
inline bool cmp2(xy x,xy y)
{
	return min(x.y-x.x,x.y-x.z)<min(y.y-y.x,y.y-y.z);
}
inline bool cmp3(xy x,xy y)
{
	return min(x.z-x.x,x.z-x.y)<min(y.z-y.y,y.z-y.x);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)scanf("%lld%lld%lld",&d[i].x,&d[i].y,&d[i].z);
		int ans=0;
		int alen=0,blen=0,clen=0;
		for(int i=1;i<=n;++i)
		{
			if(d[i].x>=d[i].y&&d[i].x>=d[i].z)a[++alen]=d[i],ans+=d[i].x;
			else if(d[i].y>=d[i].x&&d[i].y>=d[i].z)b[++blen]=d[i],ans+=d[i].y;
			else c[++clen]=d[i],ans+=d[i].z;
		}
		//printf("%lld %lld %lld %lld\n",n,alen,blen,clen);
		if(alen>n/2)
		{
			sort(a+1,a+1+alen,cmp1);
			for(int i=1;i<=alen-n/2;++i)
			{
				ans-=min(a[i].x-a[i].y,a[i].x-a[i].z);
			}
		}
		else if(blen>n/2)
		{
			sort(b+1,b+1+blen,cmp2);
			for(int i=1;i<=blen-n/2;++i)
			{
				//printf("%lld %lld\n",i,ans);
				ans-=min(b[i].y-b[i].x,b[i].y-b[i].z);
			}
		}
		else if(clen>n/2)
		{
			sort(c+1,c+1+clen,cmp3);
			for(int i=1;i<=clen-n/2;++i)
			{
				ans-=min(c[i].z-c[i].y,c[i].z-c[i].x);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
