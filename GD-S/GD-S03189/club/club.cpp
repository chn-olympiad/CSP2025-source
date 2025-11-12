#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
long long t,n,ans,p[100005],a[100005],b[100005],c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		long long a_size=0,b_size=0,c_size=0;
		vector<node>a_,b_,c_;
		for(long long i=1;i<=n;i++)
		{
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				ans+=a[i];
				a_size++;
				a_.push_back({a[i],b[i],c[i]});
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				ans+=b[i];
				b_size++;
				b_.push_back({a[i],b[i],c[i]});
			}
			else if(c[i]>=b[i]&&c[i]>=a[i])
			{
				ans+=c[i];
				c_size++;
				c_.push_back({a[i],b[i],c[i]});
			}
		}
		if(a_size>n/2)
		{
			long long k=a_size-n/2;
			for(long long i=0;i<a_size;i++)
			{
				if(a_[i].x-a_[i].y<a_[i].x-a_[i].z)
				{
					p[i]=a_[i].x-a_[i].y;
				}
				else
				{
					p[i]=a_[i].x-a_[i].z;
				}
			}
			sort(p,p+a_size);
			for(long long i=0;i<k;i++)
			{
				ans-=p[i];
			}
		}
		else if(b_size>n/2)
		{
			long long k=b_size-n/2;
			for(long long i=0;i<b_size;i++)
			{
				if(b_[i].y-b_[i].x<b_[i].y-b_[i].z)
				{
					p[i]=b_[i].y-b_[i].x;
				}
				else
				{
					p[i]=b_[i].y-b_[i].z;
				}
			}
			sort(p,p+b_size);
			for(long long i=0;i<k;i++)
			{
				ans-=p[i];
			}
		}
		else if(c_size>n/2)
		{
			long long k=c_size-n/2;
			for(long long i=0;i<c_size;i++)
			{
				if(c_[i].z-c_[i].y<c_[i].z-c_[i].x)
				{
					p[i]=c_[i].z-c_[i].y;
				}
				else
				{
					p[i]=c_[i].z-c_[i].x;
				}
			}
			sort(p,p+c_size);
			for(long long i=0;i<k;i++)
			{
				ans-=p[i];
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
