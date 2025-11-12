#include<bits/stdc++.h>
using namespace std;
long long t,n,w[5];
struct ST{
	long long a[5];
	long long x,y,z;
}p[100005];
bool cmp(ST s,ST t)
{
	if(s.a[s.x]-s.a[s.y]!=t.a[t.x]-t.a[t.y])
	{
		return s.a[s.x]-s.a[s.y]>t.a[t.x]-t.a[t.y];
	}
	else
	{
		return s.a[s.x]>t.a[t.x];
	}
}
int work()
{
	cin>>n;
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
		if(p[i].a[1]>=p[i].a[2])
		{
			if(p[i].a[1]<=p[i].a[3])
			{
				p[i].x=3;
				p[i].y=1;
				p[i].z=2;
			}
			else
			{
				if(p[i].a[3]>=p[i].a[2])
				{
					p[i].x=1;
					p[i].y=3;
					p[i].z=2;
				}
				else
				{
					p[i].x=1;
					p[i].y=2;
					p[i].z=3;
				}
			}
		}
		else
		{
			if(p[i].a[2]<=p[i].a[3])
			{
				p[i].x=3;
				p[i].y=2;
				p[i].z=1;
			}
			else
			{
				if(p[i].a[3]>=p[i].a[1])
				{
					p[i].x=2;
					p[i].y=3;
					p[i].z=1;
				}
				else
				{
					p[i].x=2;
					p[i].y=1;
					p[i].z=3;
				}
			}
		}
	}
	sort(p+1,p+n+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		if(w[p[i].x]+1<=n/2)
		{
			ans+=p[i].a[p[i].x];
			w[p[i].x]++;
		}
		else if(w[p[i].y]+1<=n/2)
		{
			ans+=p[i].a[p[i].y];
			w[p[i].y]++;
		}
		else
		{
			ans+=p[i].a[p[i].z];
			w[p[i].z]++;
		}
	}
	for(int i=1;i<=3;i++)
	{
		w[i]=0;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cout<<work()<<'\n';
	}
	return 0;
} 

