#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int first,second,third,f,s,t,ff,ss,tt;
}a[100005];
bool cmp(node x,node y)
{
	return (x.f-x.s)>(y.f-y.s);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,ans=0,sum1=0,sum2=0,sum3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].first>>a[i].second>>a[i].third;
			if(a[i].first>a[i].second)
			{
				if(a[i].first>a[i].third)
				{
					a[i].f=a[i].first;
					a[i].ff=1;
					sum1++;
					if(a[i].second<a[i].third)
					{
						a[i].s=a[i].third;
						a[i].ss=3;
						a[i].t=a[i].second;
						a[i].tt=2;
					}
					else
					{
						a[i].t=a[i].third;
						a[i].tt=3;
						a[i].s=a[i].second;
						a[i].ss=2;
					}
				}
				else
				{
					a[i].f=a[i].third;
					a[i].ff=3;
					a[i].s=a[i].first;
					a[i].ss=1;
					a[i].t=a[i].second;
					a[i].tt=2;
					sum3++;
				}
			}
			else
			{
				if(a[i].second>a[i].third)
				{
					a[i].f=a[i].second;
					a[i].ff=2;
					sum2++;
					if(a[i].first>a[i].third)
					{
						a[i].s=a[i].first;
						a[i].ss=1;
						a[i].t=a[i].third;
						a[i].tt=3;
					}
					else
					{
						a[i].t=a[i].first;
						a[i].tt=1;
						a[i].s=a[i].third;
						a[i].ss=3;
					}
				}
				else
				{
					a[i].f=a[i].third;
					a[i].ff=3;
					a[i].s=a[i].second;
					a[i].ss=2;
					a[i].t=a[i].first;
					a[i].tt=1;
					sum3++;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].f;
			}
		}
		else
		{
			if(sum1>n/2)
			{
				int cnt=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i].ff==1)
				    {
				    	if(cnt<=n/2)
				    	{
				    		ans+=a[i].f;
				    	    cnt++;
						}
				    	else
				    	{
				    		ans+=a[i].s;
				    	    cnt++;
						}
					}
				}
			    for(int i=1;i<=n;i++)
			    {
			    	if(a[i].ff!=1)
			    	{
			    		ans+=a[i].f;
					}
			    }
			}
			if(sum2>n/2)
			{
				int cnt=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i].ff==2)
				    {
				    	if(cnt<=n/2)
				    	{
				    		ans+=a[i].f;
				    	    cnt++;
						}
				    	else
				    	{
				    		ans+=a[i].s;
				    	    cnt++;
						}
					}
				}
			    for(int i=1;i<=n;i++)
			    {
			    	if(a[i].ff!=2)
			    	{
			    		ans+=a[i].f;
					}
			    }
			}
			if(sum3>n/2)
			{
				int cnt=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i].ff==3)
				    {
				    	if(cnt<=n/2)
				    	{
				    		ans+=a[i].f;
				    	    cnt++;
						}
				    	else
				    	{
				    		ans+=a[i].s;
				    	    cnt++;
						}
					}
				}
			    for(int i=1;i<=n;i++)
			    {
			    	if(a[i].ff!=3)
			    	{
			    		ans+=a[i].f;
					}
			    }
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
