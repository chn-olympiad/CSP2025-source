#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans,tot;
int cnt[5];
struct node{
	int a,b,c;
}p[100005];
bool cmp(node aa,node bb)
{
	if(aa.a!=bb.a)
	{
		return aa.a>bb.a;
	}
	else
	{
		if(aa.b!=bb.b)
		{
			return aa.b>bb.b;
		}
		else
		{
			return aa.c>bb.c;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b>>p[i].c;
		sort(p+1,p+1+n,cmp);
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i].a>p[i].b and p[i].a>p[i].c)
			{
				if(cnt[1]<n/2)
				{
					cnt[1]++;
					ans+=p[i].a;
				}
				else
				{
					if(p[i].b>p[i].c)
					{
						cnt[2]++;
						ans+=p[i].b;
					}
					else
					{
						cnt[3]++;
						ans+=p[i].c;
					}
				}
			}
			
			if(p[i].b>p[i].a and p[i].b>p[i].c)
			{
				if(cnt[2]<n/2)
				{
					cnt[2]++;
					ans+=p[i].b;
				}
				else
				{
					if(p[i].a>p[i].c)
					{
						cnt[1]++;
						ans+=p[i].a;
					}
					else
					{
						cnt[3]++;
						ans+=p[i].c;
					}
				}
			}
			
			if(p[i].c>p[i].b and p[i].c>p[i].a)
			{
				if(cnt[3]<n/2)
				{
					cnt[3]++;
					ans+=p[i].c;
				}
				else
				{
					if(p[i].b>p[i].a)
					{
						cnt[2]++;
						ans+=p[i].b;
					}
					else
					{
						cnt[1]++;
						ans+=p[i].a;
					}
				}
			}
		}
		tot=ans;
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=n;i>=1;i--)
		{
			if(p[i].a>p[i].b and p[i].a>p[i].c)
			{
				if(cnt[1]<n/2)
				{
					cnt[1]++;
					ans+=p[i].a;
				}
				else
				{
					if(p[i].b>p[i].c)
					{
						cnt[2]++;
						ans+=p[i].b;
					}
					else
					{
						cnt[3]++;
						ans+=p[i].c;
					}
				}
			}
			
			if(p[i].b>p[i].a and p[i].b>p[i].c)
			{
				if(cnt[2]<n/2)
				{
					cnt[2]++;
					ans+=p[i].b;
				}
				else
				{
					if(p[i].a>p[i].c)
					{
						cnt[1]++;
						ans+=p[i].a;
					}
					else
					{
						cnt[3]++;
						ans+=p[i].c;
					}
				}
			}
			
			if(p[i].c>p[i].b and p[i].c>p[i].a)
			{
				if(cnt[3]<n/2)
				{
					cnt[3]++;
					ans+=p[i].c;
				}
				else
				{
					if(p[i].b>p[i].a)
					{
						cnt[2]++;
						ans+=p[i].b;
					}
					else
					{
						cnt[1]++;
						ans+=p[i].a;
					}
				}
			}
		}
		tot=max(tot,ans);
		cout<<tot<<"\n";
	}
	return 0;
}
