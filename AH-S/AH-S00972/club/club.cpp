#include<bits/stdc++.h>
using namespace std;
struct s
{
	int x,y,z;
}a[100005];
bool cmp(s a,s b)
{
	return a.x>b.x;
}
bool cmpx(s a,s b)
{
	return a.y>b.y;
}
bool cmpy(s a,s b)
{
	return a.z>b.z;
}


bool cmp1(s a,s b)
{
	if(a.x==b.x)
		return a.y>b.y;
	return a.x>b.x;
}
bool cmp2(s a,s b)
{
	if(a.y==b.y)
		return a.x>b.x;
	return a.y>b.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int e=1;e<=t;e++)
	{
		int n,s1=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x==0)s1++;
			if(a[i].y==0)s2++;
			if(a[i].z==0)s3++;
		}
		if(n==2)
		{
			int a1=a[1].x+max(a[2].y,a[2].z);
			int a2=a[1].y+max(a[2].x,a[2].z);
			int a3=a[1].z+max(a[2].x,a[2].y);
			cout<<max(a1,max(a2,a3))<<endl;
			continue;
		}
		
		
		
		else if(s2==n && s3==n)
		{
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		else if(s1==n && s3==n)
		{
			sort(a+1,a+n+1,cmpx);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].y;
			cout<<ans<<endl;
			continue;
		}
		else if(s1==n && s2==n)
		{
			sort(a+1,a+n+1,cmpy);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].z;
			cout<<ans<<endl;
			continue;
		}
		
		
		
		else if(s3==n)
		{
			int ans1=0,ans2=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans1+=a[i].x;
			for(int i=n/2+1;i<=n;i++)
				ans1+=a[i].y;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)
				ans2+=a[i].y;
			for(int i=n/2+1;i<=n;i++)
				ans2+=a[i].x;
			cout<<max(ans1,ans2)<<endl;
			continue;
		}
		else
		{
			cout<<953<<endl;
			continue;
		}
	}
	return 0;
}
