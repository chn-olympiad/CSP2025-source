#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100005;
ll T,n,g1[N],g2[N],g3[N],t[N];
struct node {
	ll x,y,z;
}a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ll ans=0,s1=0,s2=0,s3=0;
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
			if (a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				s1++;
				g1[s1]=i;
				ans+=a[i].x;
				continue;
			}
			if (a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				s2++;
				g2[s2]=i;
				ans+=a[i].y;
				continue;
			}
			if (a[i].z>=a[i].x&&a[i].z>=a[i].y)
			{
				s3++;
				g3[s3]=i;
				ans+=a[i].z;
				continue;
			}
		}
		if (s1<=n/2&&s2<=n/2&&s3<=n/2)
		{
			printf("%lld\n",ans);
			for(ll i=1;i<=n;i++)
			{
				g1[i]=g2[i]=g3[i]=t[i]=0;
				a[i].x=a[i].y=a[i].z=0;
			}
			continue;
		}
		if (s1>n/2)
		{
			for(ll i=1;i<=s1;i++)
			{
				t[i]=a[g1[i]].x-max(a[g1[i]].y,a[g1[i]].z);
			}
			sort(t+1,t+s1+1);
			for(ll i=1;i<=s1-n/2;i++)
			{
				ans-=t[i];
			}
		}
		if (s2>n/2)
		{
			for(ll i=1;i<=s2;i++)
			{
				t[i]=a[g2[i]].y-max(a[g2[i]].x,a[g2[i]].z);
			}
			sort(t+1,t+s2+1);
			for(ll i=1;i<=s2-n/2;i++)
			{
				ans-=t[i];
			}
		}
		if (s3>n/2)
		{
			for(ll i=1;i<=s3;i++)
			{
				t[i]=a[g3[i]].z-max(a[g3[i]].x,a[g3[i]].y);
			}
			sort(t+1,t+s3+1);
			for(ll i=1;i<=s3-n/2;i++)
			{
				ans-=t[i];
			}
		}
		printf("%lld\n",ans);
		for(ll i=1;i<=n;i++)
		{
			a[i].x=a[i].y=a[i].z=0;
			g1[i]=g2[i]=g3[i]=0;
			t[i]=0;
		}
		s1=s2=s3=0;
	}
	return 0;
}
