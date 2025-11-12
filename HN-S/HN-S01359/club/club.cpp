#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;


const int N=1e5+100;

struct club 
{
	int p,num,x;
}d[N];

int a,b,c;
int x;
//int p[N];
int pt;
long long ans=0;

bool cmp(club a,club b)
{
	if(a.p!=pt&&b.p!=pt)
	{
		return a.p>b.p;
	}
	if(a.p!=pt&&b.p==pt)
	{
		return false;
	}
	if(a.p==pt&&b.p!=pt)
	return true;
	return a.x<b.x;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		ans=0;
		x=0;
		a=b=c=0;
		pt=0;
		int n;
		scanf("%d",&n);
		for(int t=1;t<=n;t++)
		{
			int da,db,dc;
			scanf("%d%d%d",&da,&db,&dc);
			if(da>=db&&da>=dc)
			{
				d[t].p=1;
				d[t].num=da;
				d[t].x=da-max(db,dc);
				ans+=da;
				a++;
			}
			else
			if(db>=da&&db>=dc)
			{
				d[t].p=2;
				d[t].num=db;
				d[t].x=db-max(da,dc);
				ans+=db;
				b++;
			}
			else
			if(dc>=da&&dc>=db)
			{
				d[t].p=3;
				d[t].num=dc;
				d[t].x=dc-max(da,db);
				ans+=dc;
				c++;
			}
		}
		bool flag=false;
		if(a>=b&&a>=c)
		{
			pt=1;
			if(a>(n>>1))
			{
				x=a-(n>>1);
				flag=true;
			}
		}
		else
		if(b>=a&&b>=c)
		{
			pt=2;
			if(b>(n>>1))
			{
				x=b-(n>>1);
				flag=true;
			}
		}
		else
		if(c>=a&&c>=b)
		{
			pt=3;
			if(c>(n>>1))
			{
				x=c-(n>>1);
				flag=true;
			}
		}
		if(flag)
		{
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=x;i++)
			{
				ans-=d[i].x;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
