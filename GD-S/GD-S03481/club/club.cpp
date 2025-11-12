#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll ma=1e5+100;
ll t;
ll n;
ll c[3];
ll a[ma][3];
ll ans;
ll temp;
ll b=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&a[i][0]);
			scanf("%lld",&a[i][1]);
			scanf("%lld",&a[i][2]);
			if(a[i][1]!=0)
			{
				b=1;
				if(a[i][2]!=0)
				{
					b=2;
				}
			}
			if(a[i][2]!=0)
			{
				b=2;
			}
		}
		temp=n;
		if(b==0)
		{
			ll ag[temp];
			for(ll i=0;i<n;i++)
			{
				ag[i]=a[i][0];
			}
			sort(ag,ag+temp);
			for(ll i=0;i<=temp/2;i++)
			{
				ans+=ag[i];
			}
		}
		if(b==1)
		{
			ll ag1[temp],ag2[temp];
			for(ll i=0;i<n;i++)
			{
				ag1[i]=a[i][0];
				ag2[i]=a[i][1];
			}
			sort(ag1,ag1+temp);
			sort(ag2,ag2+temp);
			for(ll i=0;i<n;i++)
			{
				ans+=max(ag1[i],ag2[i]);
			}
		}
		if(b==2)
		{
			ll ag1[temp],ag2[temp],ag3[temp];
			ll x=0,y=0,z=0;
			for(ll i=0;i<n;i++)
			{
				ag1[i]=a[i][0];
				ag2[i]=a[i][1];
				ag3[i]=a[i][2];
			}
			sort(ag1,ag1+temp);
			sort(ag2,ag2+temp);
			sort(ag2,ag2+temp);
			for(ll i=0;i<n;i++)
			{
				ans+=max(ag1[i],max(ag2[i],ag3[i]));
			}
		}
		printf("%lld\n",ans);
	}
	return 0; 
} 
