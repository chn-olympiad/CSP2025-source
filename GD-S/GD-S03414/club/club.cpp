#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans,ans1,ans2,sx,sy,sz;
struct node{
	ll x,y,z;
}a[100005];
bool cmp(node a,node b)
{
	if(a.x-max(a.y,a.z)!=b.x-max(b.y,b.z))return a.x-max(a.y,a.z)>b.x-max(b.y,b.z);
}
bool cmp1(node a,node b)
{
	if(a.y-max(a.x,a.z)!=b.y-max(b.x,b.z))return a.y-max(a.x,a.z)>b.y-max(b.x,b.z);
}
bool cmp2(node a,node b)
{
	if(a.z-max(a.y,a.x)!=b.z-max(b.y,b.x))return a.z-max(a.y,a.x)>b.z-max(b.y,b.x);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		ans=ans1=ans2=0;
		sort(a+1,a+n+1,cmp);
		sx=sy=sz=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x-max(a[i].y,a[i].z)>=a[i+1].x-max(a[i+1].y,a[i+1].z)||sy+1==n/2&&sz+1==n/2){
				if(sx<n/2)sx++,ans+=a[i].x;
				else{
					if(a[i].y>a[i].z)sy++,ans+=a[i].y;
					if(a[i].y<a[i].z)sz++,ans+=a[i].z;
					if(a[i].y==a[i].z){
						if(sy<=sz)sy++,ans+=a[i].y;
						else sz++,ans+=a[i].z;
					}
				}
			}
			else if(a[i].y>a[i].z&&sy<n/2)sy++,ans+=a[i].y;
			else sz++,ans+=a[i].z;
		}
		sort(a+1,a+n+1,cmp1);
		sx=sy=sz=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].y-max(a[i].x,a[i].z)>a[i+1].y-max(a[i+1].x,a[i+1].z)||sx+1==n/2&&sz+1==n/2){
				if(sy<n/2)sy++,ans1+=a[i].y;
				else{
					if(a[i].x>a[i].z)sx++,ans1+=a[i].x;
					if(a[i].x<a[i].z)sz++,ans1+=a[i].z;
					if(a[i].x==a[i].z){
						if(sx<=sz)sx++,ans1+=a[i].x;
						else sz++,ans1+=a[i].z;
					}
				}
			}
			else if(a[i].x>a[i].z&&sx<n/2)sx++,ans1+=a[i].x;
			else sz++,ans1+=a[i].z;
		}
		sort(a+1,a+n+1,cmp2);
		sx=sy=sz=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].z-max(a[i].y,a[i].x)>=a[i+1].z-max(a[i+1].y,a[i+1].x)||sy+1==n/2&&sx+1==n/2){
				if(sz<n/2)sz++,ans2+=a[i].z;
				else{
					if(a[i].y>a[i].x)sy++,ans2+=a[i].y;
					if(a[i].y<a[i].x)sz++,ans2+=a[i].x;
					if(a[i].y==a[i].x){
						if(sy<=sx)sy++,ans2+=a[i].y;
						else sx++,ans2+=a[i].x;
					}
				}
			}
			else if(a[i].y>a[i].x&&sy<n/2)sy++,ans2+=a[i].y;
			else sx++,ans2+=a[i].x;
		}
		printf("%lld\n",max({ans,ans1,ans2}));
	}
	return 0;
}
