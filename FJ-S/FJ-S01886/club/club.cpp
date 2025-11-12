#include <bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],ans,suma,sumb,sumc;
struct node
{
	long long xa,xb,xc;
} e[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));
		ans=0;
		suma=sumb=sumc=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&e[i].xa,&e[i].xb,&e[i].xc);
			if (e[i].xa>=e[i].xb&&e[i].xa>=e[i].xc)
			{
				a[++suma]=i;
				ans+=e[i].xa;
			}
			else if (e[i].xb>=e[i].xa&&e[i].xb>=e[i].xc)
			{
				b[++sumb]=i;
				ans+=e[i].xb;
			}
			else
			{
				c[++sumc]=i;
				ans+=e[i].xc;
			}
		}
		if (suma>n/2)
		{
			for(int i=1;i<=suma;i++)
			{
				a[i]=min(e[a[i]].xa-e[a[i]].xb,e[a[i]].xa-e[a[i]].xc);
			}
			sort(a+1,a+suma+1);
			for(int i=1;i<=suma-n/2;i++)
			{
				ans-=a[i];
			}
		}
		if (sumb>n/2)
		{
			for(int i=1;i<=sumb;i++)
			{
				b[i]=min(e[b[i]].xb-e[b[i]].xa,e[b[i]].xb-e[b[i]].xc);
			}
			sort(b+1,b+sumb+1);
			for(int i=1;i<=sumb-n/2;i++)
			{
				ans-=b[i];
			}
		}
		if (sumc>n/2)
		{
			for(int i=1;i<=sumc;i++)
			{
				c[i]=min(e[c[i]].xc-e[c[i]].xb,e[c[i]].xc-e[c[i]].xa);
			}
			sort(c+1,c+sumc+1);
			for(int i=1;i<=sumc-n/2;i++)
			{
				ans-=c[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

