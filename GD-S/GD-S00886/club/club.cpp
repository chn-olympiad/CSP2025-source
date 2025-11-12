#include<bits/stdc++.h>
using namespace std;
long long t,n,d[10],da,p;
struct h
{
	long long a,b,c,id,kaa;
}e[100005];

bool cmpp(h x,h y)
{
	return x.kaa<y.kaa;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].c);
			if(e[i].a>max(e[i].b,e[i].c))
			{
				da+=e[i].a,d[1]++,e[i].id=1;
				e[i].kaa=e[i].a-max(e[i].b,e[i].c);
			}
			else if(e[i].b>e[i].c)
			{
				da+=e[i].b,d[2]++,e[i].id=2;
				e[i].kaa=e[i].b-max(e[i].a,e[i].c);
			}
			else 
			{
				da+=e[i].c,d[3]++,e[i].id=3;
				e[i].kaa=e[i].c-max(e[i].a,e[i].b); 
			}
			
		}
		if(d[1]>n/2)p=1;
		if(d[2]>n/2)p=2;
		if(d[3]>n/2)p=3;
		sort(e+1,e+1+n,cmpp);
		for(int i=1;i<=n;i++)
		{
			if(e[i].id==p&&d[p]>n/2)
			{
				da-=e[i].kaa;
				d[p]--;
			}
		}
		cout<<da<<endl;
		for(int i=1;i<=n;i++)
		{
			e[i].kaa=0;e[i].id=0;
			da=0;
		}
		d[1]=0;d[2]=0;d[3]=0;
		}
	return 0;
} 
