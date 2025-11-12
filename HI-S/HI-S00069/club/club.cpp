#include"bits/stdc++.h"
using namespace std;
int t;
struct bb
{
	long long b1,b2,b3;
	long long y1,y2,y3,cz;
}a[100010],x1[100010],x2[100010],x3[100010];
bool cmp(bb x,bb y)
{
	return x.cz>y.cz;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long s1=0,s2=0,s3=0;
		long long ans=0;
		long long n;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i].b1>>a[i].b2>>a[i].b3;
			a[i].y1=1,a[i].y2=2,a[i].y3=3;
			if(a[i].b1<a[i].b2){swap(a[i].b1,a[i].b2);swap(a[i].y1,a[i].y2);}
			if(a[i].b1<a[i].b3){swap(a[i].b1,a[i].b3);swap(a[i].y1,a[i].y3);}
			if(a[i].b2<a[i].b3){swap(a[i].b2,a[i].b3);swap(a[i].y2,a[i].y3);}
			a[i].cz=a[i].b1-a[i].b2;
			if(a[i].y1==1){s1++;x1[s1]=a[i];}
			if(a[i].y1==2){s2++;x2[s2]=a[i];}
			if(a[i].y1==3){s3++;x3[s3]=a[i];}
		}
		if(!max(max(s1,s2),s3)>n/2)
		{
			for(long long i=1;i<=n;i++)
			ans+=a[i].b1;
			cout<<ans<<endl;
		}
		else
		{
			if(max(max(s1,s2),s3)==s1)
			{
				sort(x1+1,x1+s1+1,cmp);
				for(long long i=1;i<=n/2;i++)
				{
					ans+=x1[i].b1;
				}
				for(long long i=n/2+1;i<=s1;i++)
				{
					ans+=x1[i].b2;
				}
				for(long long i=1;i<=s2;i++)
				{
					ans+=x2[i].b1;
				}
				for(long long i=1;i<=s3;i++)
				{
					ans+=x3[i].b1;
				}
			}
			else if(max(max(s1,s2),s3)==s2)
			{
				sort(x2+1,x2+s2+1,cmp);
				for(long long i=1;i<=n/2;i++)
				{
					ans+=x2[i].b1;
				}
				for(long long i=n/2+1;i<=s2;i++)
				{
					ans+=x2[i].b2;
				}
				for(long long i=1;i<=s1;i++)
				{
					ans+=x1[i].b1;
				}
				for(long long i=1;i<=s3;i++)
				{
					ans+=x3[i].b1;
				}
			}
			else if(max(max(s1,s2),s3)==s3)
			{
				sort(x3+1,x3+s3+1,cmp);
				for(long long i=1;i<=n/2;i++)
				{
					ans+=x3[i].b1;
				}
				for(long long i=n/2+1;i<=s3;i++)
				{
					ans+=x3[i].b2;
				}
				for(long long i=1;i<=s2;i++)
				{
					ans+=x2[i].b1;
				}
				for(long long i=1;i<=s1;i++)
				{
					ans+=x1[i].b1;
				}
			}
			cout<<ans<<endl;
		}
	}
}
