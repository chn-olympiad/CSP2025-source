#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,t1,t2,t3,as,z,y,p[105];
struct node
{
	int f,s,h,d1,d2,d3,c1,c2,c3,ma;
}a[100005];
bool cmp(node c,node d)
{
	return c.ma>d.ma;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		t1=0,t2=0,t3=0,z=0,y=0,as=0;
		p[1]=0,p[2]=0,p[3]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].f,&a[i].s,&a[i].h);
			a[i].c1=min(a[i].f-a[i].s,a[i].f-a[i].h);
			a[i].c2=min(a[i].s-a[i].f,a[i].s-a[i].h);
			a[i].c3=min(a[i].h-a[i].f,a[i].h-a[i].s);
			if(a[i].c1>=a[i].c2&&a[i].c2>=a[i].c3)
			{
				a[i].d1=1,a[i].d2=2,a[i].d3=3;
			}
			else  if(a[i].c1>=a[i].c3&&a[i].c3>=a[i].c2)  a[i].d1=1,a[i].d2=3,a[i].d3=2;
			else  if(a[i].c2>=a[i].c1&&a[i].c1>=a[i].c3)  a[i].d1=2,a[i].d2=1,a[i].d3=3;
			else  if(a[i].c2>=a[i].c3&&a[i].c3>=a[i].c1)  a[i].d1=2,a[i].d2=3,a[i].d3=1;
			else  if(a[i].c3>=a[i].c2&&a[i].c2>=a[i].c1)  a[i].d1=3,a[i].d2=2,a[i].d3=1;
			else  a[i].d1=3,a[i].d2=1,a[i].d3=2;
			a[i].ma=max(a[i].c1,max(a[i].c2,a[i].c3));
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(p[a[i].d1]<n/2)
			{
				if(a[i].d1==1)  as+=a[i].f;
				if(a[i].d1==2)  as+=a[i].s;
				if(a[i].d1==3)  as+=a[i].h;
				p[a[i].d1]++;
				
			}
			else  if(p[a[i].d2]<n/2)
			{
				if(a[i].d2==1)  as+=a[i].f;
				if(a[i].d2==2)  as+=a[i].s;
				if(a[i].d2==3)  as+=a[i].h;
				p[a[i].d2]++;
			}
			else
			{
				if(a[i].d3==1)  as+=a[i].f;
				if(a[i].d3==2)  as+=a[i].s;
				if(a[i].d3==3)  as+=a[i].h;
				p[a[i].d3]++;
			}
		}
		printf("%lld\n",as);
	}
	return 0;
} 
