#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;
int t,n,cc[N],vis[N];
struct ppl
{
	int a,b,c;
}a[N];
struct _
{
	int dif,ix,c;
	bool friend operator<(_ x,_ y) {return x.dif>y.dif;}
};

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(cc,0,sizeof cc);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		  scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		int ans=0,ta=0,tb=0,tc=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>=a[i].b && a[i].a>=a[i].c)
			  ta++,ans+=a[i].a,cc[i]=1;
			else if(a[i].b>=a[i].a && a[i].b>=a[i].c)
			  tb++,ans+=a[i].b,cc[i]=2;
			else if(a[i].c>=a[i].a && a[i].c>=a[i].b)
			  tc++,ans+=a[i].c,cc[i]=3;
		}
//		printf("%lld %lld %lld\n",ta,tb,tc);
//		for(int i=1;i<=n;i++)
//		  printf("%lld %lld\n",i,cc[i]);
		priority_queue<_> qa;
		priority_queue<_> qb;
		priority_queue<_> qc;
		for(int i=1;i<=n;i++)
		{
			if(cc[i]==1 && ta>n/2)
			{
				qa.push({a[i].a-a[i].b,i,2});
				qa.push({a[i].a-a[i].c,i,3});
			}
			if(cc[i]==2 && tb>n/2)
			{
				qb.push({a[i].b-a[i].a,i,1});
				qb.push({a[i].b-a[i].c,i,3});
			}
			if(cc[i]==3 && tc>n/2)
			{
				qc.push({a[i].c-a[i].b,i,2});
				qc.push({a[i].c-a[i].a,i,1});
			}
		}
		memset(vis,0,sizeof vis);
		while(ta>n/2 && !qa.empty())
		{
			int dif=qa.top().dif;
			int ix=qa.top().ix;
			int c=qa.top().c;
			qa.pop();
			if(vis[ix])
			  continue;
			vis[ix]=1;
			cc[ix]=c;
			ans-=dif;
			ta--;
		}
		memset(vis,0,sizeof vis);
		while(tb>n/2 && !qb.empty())
		{
			int dif=qb.top().dif;
			int ix=qb.top().ix;
			int c=qb.top().c;
			qb.pop();
			if(vis[ix])
			  continue;
			vis[ix]=1;
			cc[ix]=c;
			ans-=dif;
			tb--;
		}
		memset(vis,0,sizeof vis);
		while(tc>n/2 && !qc.empty())
		{
			int dif=qc.top().dif;
			int ix=qc.top().ix;
			int c=qc.top().c;
			qc.pop();
			if(vis[ix])
			  continue;
			vis[ix]=1;
			cc[ix]=c;
			ans-=dif;
			tc--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
