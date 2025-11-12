#include<bits/stdc++.h>
using namespace std;
struct da{
	long long x,y,z;
}a[100010];
long long T,n;
bool cmp(da o,da p)
{
	long long ma,mi;
	if((o.y>=o.x&&o.x>=o.z)||(o.z>=o.x&&o.x>=o.y))
	{
		ma=o.x;
	}
	if((o.x>=o.y&&o.y>=o.z)||(o.z>=o.y&&o.y>=o.x))
	{
		ma=o.y;
	}
	if((o.y>=o.z&&o.z>=o.x)||(o.x>=o.z&&o.z>=o.y))
	{
		ma=o.z;
	}
	if((p.y>=p.x&&p.x>=p.z)||(p.z>=p.x&&p.x>=p.y))
	{
		mi=p.x;
	}
	if((p.x>=p.y&&p.y>=p.z)||(p.z>=p.y&&p.y>=p.x))
	{
		mi=p.y;
	}
	if((p.y>=p.z&&p.z>=p.x)||(p.x>=p.z&&p.z>=p.y))
	{
		mi=p.z;
	}
	return ma>mi;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		long long ans=0,l[4]={0,0,0,0};
		for(int i=1;i<=n;i++)
		{
			ans+=max(a[i].x,max(a[i].y,a[i].z));
			long long t1,t2,t3;
			t1=a[i].x;t2=a[i].y;t3=a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				l[1]++;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				l[2]++;
			}
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
			{
				l[3]++;
			}
			a[i].x=a[i].x-max(t1,max(t2,t3));
			a[i].y=a[i].y-max(t1,max(t2,t3));
			a[i].z=a[i].z-max(t1,max(t2,t3));
		}
		if(l[1]>(n/2))
		{
			sort(a+1,a+1+n,cmp);
			long long r=0;
			for(int i=1;i<=n,r<(l[1]-(n/2));i++)
			{
				if(a[i].x==0)
				{
					r++;
					ans+=max(a[i].y,a[i].z);
				}
			}
		}
		else if(l[2]>(n/2))
		{
			sort(a+1,a+1+n,cmp);
			long long r=0;
			for(int i=1;i<=n,r<(l[2]-(n/2));i++)
			{
				if(a[i].y==0)
				{
					r++;
					ans+=max(a[i].x,a[i].z);
				}
			}
		}
		else if(l[3]>(n/2))
		{
			sort(a+1,a+1+n,cmp);
			long long r=0;
			for(int i=1;i<=n,r<(l[3]-(n/2));i++)
			{
				if(a[i].z==0)
				{
					r++;
					ans+=max(a[i].y,a[i].x);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
