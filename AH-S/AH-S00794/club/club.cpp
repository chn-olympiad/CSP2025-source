#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c,maxx,cc;
}s[100005];
bool cmp(node x,node y){return x.cc>y.cc;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		long long n,ans=0,q1=0,q2=0,q3=0,qq1=0,qq2=0,qq3=0;
		cin>>n; 
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].maxx=max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].maxx==s[i].a)s[i].cc=s[i].maxx-max(s[i].b,s[i].c);
			if(s[i].maxx==s[i].b)s[i].cc=s[i].maxx-max(s[i].a,s[i].c);
			if(s[i].maxx==s[i].c)s[i].cc=s[i].maxx-max(s[i].b,s[i].a);
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i].maxx==s[i].a)q1++;
			if(s[i].maxx==s[i].b)q2++;
			if(s[i].maxx==s[i].c)q3++;
		}
		sort(s+1,s+n+1,cmp);
		if(q1>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i].maxx!=s[i].a)
				{
					continue;
				}
				if(qq1>=n/2)
				{
					if(s[i].b>s[i].c)
					{
						s[i].maxx=s[i].b;
						s[i].cc=s[i].b-max(s[i].a,s[i].c);
					}
					else
					{
						s[i].maxx=s[i].c;
						s[i].cc=s[i].c-max(s[i].a,s[i].b);
					}
				}
				if(qq1<n/2)
				{
					qq1++;
				}
			}
		}
		if(q2>n/2)
		{
			
			for(int i=1;i<=n;i++)
			{
				if(s[i].maxx!=s[i].b)
				{
					continue;
				}
				if(qq2>=n/2)
				{
					if(s[i].a>s[i].c)
					{
						s[i].maxx=s[i].a;
						s[i].cc=s[i].a-max(s[i].c,s[i].b);
					}
					else
					{
						s[i].maxx=s[i].c;
						s[i].cc=s[i].c-max(s[i].b,s[i].a);
					}
				}
				if(qq2<n/2)
				{
					qq2++;
				}
			}
		}
		if(q3>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i].maxx!=s[i].c)
				{
					continue;
				}
				if(qq3>=n/2)
				{
					if(s[i].b>s[i].a)
					{
						s[i].maxx=s[i].b;
						s[i].cc=s[i].b-max(s[i].c,s[i].a);
					}
					else
					{
						s[i].maxx=s[i].a;
						s[i].cc=s[i].a-max(s[i].b,s[i].c);
					}
				}
				if(qq3<n/2)
				{
					qq3++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=s[i].maxx;
		}
		cout<<ans<<endl;
	}
	return 0;
}
