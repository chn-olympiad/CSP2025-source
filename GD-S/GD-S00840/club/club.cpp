#include<bits/stdc++.h>
using namespace std;
long long t,n,sum1,sum2,sum3,ans;
struct node
{
	long long md,mx,md_,mx_;
}a[100005];
bool cmp(node x,node y)
{
	return (x.mx-x.md)>(y.mx-y.md);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0,sum1=0,sum2=0,sum3=0;
		long long t1,t2,t3;
		for(int i=1;i<=n;i++)
		{
			cin>>t1>>t2>>t3;
			if(t1>=t2&&t2>=t3)
				a[i].md_=2,a[i].md=t2;
			if(t2>=t3&&t3>=t1)
				a[i].md_=3,a[i].md=t3;
			if(t3>=t1&&t1>=t2)
				a[i].md_=1,a[i].md=t1;
			if(t3>=t2&&t2>=t1)
				a[i].md_=2,a[i].md=t2;
			if(t1>=t3&&t3>=t2)
				a[i].md_=3,a[i].md=t3;
			if(t2>=t1&&t1>=t3)
				a[i].md_=1,a[i].md=t1;
				
			if(t1>=t2&&t1>=t3)
				a[i].mx_=1,a[i].mx=t1;
			if(t2>=t1&&t2>=t3)
				a[i].mx_=2,a[i].mx=t2;
			if(t3>=t2&&t3>=t1)
				a[i].mx_=3,a[i].mx=t3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].mx_==1)
			{
				if(sum1*2<n)
				{
					ans+=a[i].mx;
					sum1++;
				}
				else
				{
					ans+=a[i].md;
					if(a[i].md_==2)
						sum2++;
					else
						sum3++;
				}
			}
			else if(a[i].mx_==2)
			{
				if(sum2*2<n)
				{
					ans+=a[i].mx;
					sum2++;
				}
				else
				{
					ans+=a[i].md;
					if(a[i].md_==1)
						sum1++;
					else
						sum3++;
				}
			}
			else if(a[i].mx_==3)
			{
				if(sum3*2<n)
				{
					ans+=a[i].mx;
					sum3++;
				}
				else
				{
					ans+=a[i].md;
					if(a[i].md_==2)
						sum2++;
					else
						sum1++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
