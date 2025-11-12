#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct node1
{
	int a1,a2,a3,flag;
}a[100010];
bool cmp1(node1 x,node1 y)
{
	return x.a1>y.a1;
}
bool cmp2(node1 x,node1 y)
{
	return x.a2>y.a2;
}
bool cmp3(node1 x,node1 y)
{
	return x.a3>y.a3;
}			
long long t,n,ans1=0,ans=0,f=0;
int main()
{
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	stdin;
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		ans1=ans=0;
		cin>>n;
		for(long long j=1;j<=n;j++)
		{
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			a[j].flag=1;
		}
		f=0;
		sort(a+1,a+n+1,cmp1);
		for(long long j=1;j<=n;j++)
		{
			if(3*j<n+1)
			{
				ans1+=a[j].a1;
				a[j].flag=0;
				f++;
			}
			else if(f<(n/2))
			{
				if(max(a[j].a1,max(a[j].a2,a[j].a3))==a[j].a1) f++;
				ans1+=max(a[j].a1,max(a[j].a2,a[j].a3));
			}
			else ans1+=max(a[j].a2,a[j].a3);
		}
		ans=max(ans,ans1);
////////////////////////////////////////////////////////////////////////
		ans1=0;
		for(long long j=1;j<=n;j++)
		{
			a[j].flag=1;
		}
		f=0;
		sort(a+1,a+n+1,cmp2);
		for(long long j=1;j<=n;j++)
		{
			if(3*j<n+1)
			{
				ans1+=a[j].a2;
				a[j].flag=0;
				f++;
			}
			else if(f<(n/2))
			{
				if(max(a[j].a1,max(a[j].a2,a[j].a3))==a[j].a2) f++;
				ans1+=max(a[j].a1,max(a[j].a2,a[j].a3));
			}
			else ans1+=max(a[j].a1,a[j].a3);
		}
		ans=max(ans,ans1);
////////////////////////////////////////////////////////////////////////
		ans1=0;
		for(long long j=1;j<=n;j++)
		{
			a[j].flag=1;
		}
		f=0;
		sort(a+1,a+n+1,cmp3);
		for(long long j=1;j<=n;j++)
		{
			if(3*j<n+1)
			{
				ans1+=a[j].a3;
				a[j].flag=0;
				f++;
			}
			else if(f<(n/2))
			{
				if(max(a[j].a1,max(a[j].a2,a[j].a3))==a[j].a3) f++;
				ans1+=max(a[j].a1,max(a[j].a2,a[j].a3));
			}
			else ans1+=max(a[j].a1,a[j].a2);
		}
		ans=max(ans,ans1);
		cout<<ans<<endl;
		stdout;
	}	
	return 0;
}
