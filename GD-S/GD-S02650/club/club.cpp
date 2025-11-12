#include<bits/stdc++.h>
using namespace std;
long long int fa[100005];
long long int fb[100005];
long long int fc[100005];
long long int ans;
struct node{
	int a;
	int b;
	int c;
	int d;
	int fir;
	int sec;
}s[100005];
int n,cnta,cntb,cntc,t;
bool cmp(const node & a,const node & b)
{
	return a.d>b.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int x,y;
	while(t)
	{
	t--;
	ans=0;
	cnta=cntb=cntc=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		x=max(s[i].a,max(s[i].b,s[i].c));
		if(x==s[i].a)
		{
			s[i].fir=1;
			y=max(s[i].b,s[i].c);
			if(y==s[i].b)
			{
				s[i].sec=2;
			}
			else
			{
				s[i].sec=3;
			}
		}
		if(x==s[i].b)
		{
			s[i].fir=2;
			y=max(s[i].a,s[i].c);
			if(y==s[i].a)
			{
				s[i].sec=1;
			}
			else
			{
				s[i].sec=3;
			}
		}
		if(x==s[i].c)
		{
			s[i].fir=3;
			y=max(s[i].a,s[i].b);
			if(y==s[i].a)
			{
				s[i].sec=1;
			}
			else
			{
				s[i].sec=2;
			}
		}
		s[i].d=x-y;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(s[i].fir==1)
		{
			if(cnta<n/2)
			{
				ans+=s[i].a;
				cnta++;
			}
			else
			{
				if(s[i].sec==2)
				{
					if(cntb<n/2)
					{
						ans+=s[i].b;
						cntb++;
					}
					else
					{
						ans+=s[i].c;
					}
				}
				else
				{
					if(cntc<n/2)
					{
						ans+=s[i].c;
						cntc++;
					}
					else
					{
						ans+=s[i].b;
					}
				}
			}
		}
		if(s[i].fir==2)
		{
			if(cntb<n/2)
			{
				ans+=s[i].b;
				cntb++;
			}
			else
			{
				if(s[i].sec==1)
				{
					if(cnta<n/2)
					{
						ans+=s[i].a;
						cnta++;
					}
					else
					{
						ans+=s[i].c;
					}
				}
				else
				{
					if(cntc<n/2)
					{
						ans+=s[i].c;
						cntc++;
					}
					else
					{
						ans+=s[i].b;
					}
				}
			}
		}
		if(s[i].fir==3)
		{
			if(cntc<n/2)
			{
				ans+=s[i].c;
				cntc++;
			}
			else
			{
				if(s[i].sec==1)
				{
					if(cnta<n/2)
					{
						ans+=s[i].a;
						cnta++;
					}
					else
					{
						ans+=s[i].b;
					}
				}
				else
				{
					if(cntb<n/2)
					{
						ans+=s[i].b;
						cntb++;
					}
					else
					{
						ans+=s[i].a;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	}
	return 0;
}
