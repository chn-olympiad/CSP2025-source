#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[100001],b[100001],c[100001],ans,x[100001],y[100001],z[100001],sum[3],maxx;
bool cmp(ll u,ll v)
{
	return u>v;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum[0]=0,sum[1]=0,sum[2]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			maxx=max(a[i],max(b[i],c[i]));
			if(a[i]==maxx)
			{
				ans+=a[i];
				sum[0]++;
				if(b[i]>=c[i])
				{
					x[sum[0]]=(b[i]-a[i]);
				}
				else
				{
					x[sum[0]]=(c[i]-a[i]);
				}
			}
			else
			{
				if(b[i]==maxx)
				{
					ans+=b[i];
					sum[1]++;
					if(c[i]>=a[i])
					{
						y[sum[1]]=(c[i]-b[i]);
					}
					else
					{
						y[sum[1]]=(a[i]-b[i]);
					}
				}
				else
				{
					ans+=c[i];
					sum[2]++;
					if(b[i]>=a[i])
					{
						z[sum[2]]=(b[i]-c[i]);
					}
					else
					{
						z[sum[2]]=(a[i]-c[i]);
					}
				}
			}
		}
		if(sum[0]>n/2)
		{
			sort(x+1,x+1+sum[0],cmp);
			for(int i=1;i<=sum[0]-n/2;i++)
			{
				ans+=x[i];
			}
		}
		else
		{
			if(sum[1]>n/2)			
			{
				sort(y+1,y+1+sum[1],cmp);
				for(int i=1;i<=sum[1]-n/2;i++)
				{
					ans+=y[i];
				}
			}
			else
			{
				if(sum[2]>n/2)
				{
					sort(z+1,z+1+sum[2],cmp);
					for(int i=1;i<=sum[2]-n/2;i++)
					{
						ans+=z[i];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
