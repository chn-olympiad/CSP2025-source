#include<bits/stdc++.h>
#define N 100005
#define M 100005
#define int long long
using namespace std;
int n,sum,sx,sy,sz,x[N],y[N],z[N];
struct node
{
	int a,b,c,ma,ma2,sum,z;
}a[N];
bool cmp(node ss,node sss)
{
	if(ss.z!=sss.z)
	{
		return ss.z<sss.z;
	}
	return ss.ma-ss.ma2<sss.ma-sss.ma2;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		sum=0;
		sx=0;
		sy=0;
		sz=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].ma=max(a[i].a,max(a[i].b,a[i].c));
			a[i].sum=a[i].a+a[i].b+a[i].c;
			if((a[i].a>=a[i].b&&a[i].b>=a[i].c) || (a[i].c>=a[i].b&&a[i].b>=a[i].a))
			{
				a[i].ma2=a[i].b;
			}
			if((a[i].b>=a[i].a&&a[i].a>=a[i].c) || (a[i].c>=a[i].a&&a[i].a>=a[i].b))
			{
				a[i].ma2=a[i].a;
			}
			if((a[i].b>=a[i].c&&a[i].c>=a[i].a) || (a[i].a>=a[i].c&&a[i].c>=a[i].b))
			{
				a[i].ma2=a[i].c;
			}
			sum+=a[i].ma;
			if(a[i].ma==a[i].a)
			{
				sx++;
				a[i].z=1;
			}
			else if(a[i].ma==a[i].b)
			{
				sy++;
				a[i].z=2;
			}
			else
			{
				sz++;
				a[i].z=3;
			}
		}
		sort(a+1,a+1+n,cmp);
		if(sx>n/2)
		{
			for(int i=1;i<=sx-n/2;i++)
			{
				sum-=a[i].ma;
				sum+=a[i].ma2;
			}
		}
		if(sy>n/2)
		{
			for(int i=sx+1;i<=sx+sy-n/2;i++)
			{
				sum-=a[i].ma;
				sum+=a[i].ma2;
			}
		}
		if(sz>n/2)
		{
			for(int i=sx+sy+1;i<=sx+sy+sz-n/2;i++)
			{
				sum-=a[i].ma;
				sum+=a[i].ma2;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
