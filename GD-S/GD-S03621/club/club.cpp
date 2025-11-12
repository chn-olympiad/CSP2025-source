#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct zs
{
	long long l1;
	long long l2;
	long long l3;
	int p;
}a[100010];
struct zm
{
	int num;
	int f;
}sm[100010];
bool cmp(zm x,zm y)
{
	return x.num<y.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int t1=0,t2=0,t3=0;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].l1,&a[i].l2,&a[i].l3);
			if(a[i].l1>=a[i].l2&&a[i].l1>=a[i].l3)
			{
				a[i].p=a[i].l1;
				t1++;
			}
			else if(a[i].l2>=a[i].l1&&a[i].l2>=a[i].l3)
			{
				a[i].p=a[i].l2;
				t2++;
			}
			else
			{
				a[i].p=a[i].l3;
				t3++;
			}
		}
		if(max(t1,max(t2,t3))>n/2)
		{
			int ii=1;
			for(int i=1;i<=n;i++)
			{
				if(t1>n/2)
				{
					if(a[i].p==a[i].l1)
					{
						sm[ii].num=a[i].l1-max(a[i].l2,a[i].l3);
						sm[ii].f=i;
						ii++;
					}
				}
				else if(t2>n/2)
				{
					if(a[i].p==a[i].l2)
					{
						sm[ii].num=a[i].l2-max(a[i].l1,a[i].l3);
						sm[ii].f=i;
						ii++;
					}
				}
				else
				{
					if(a[i].p==a[i].l3)
					{
						sm[ii].num=a[i].l3-max(a[i].l1,a[i].l2);
						sm[ii].f=i;
						ii++;
					}
				}
			}
			ii--;
			sort(sm+1,sm+ii+1,cmp);
			for(int i=1;i<=max(t1,max(t2,t3))-(n/2);i++)
			{
				if(t1>n/2)
				{
					a[sm[i].f].p=max(a[sm[i].f].l2,a[sm[i].f].l3);
				}
				else if(t2>n/2)
				{
					a[sm[i].f].p=max(a[sm[i].f].l1,a[sm[i].f].l3);
				}
				else
				{
					a[sm[i].f].p=max(a[sm[i].f].l1,a[sm[i].f].l2);
				}
			}
			for(int i=1;i<=ii;i++)
			{
				sm[i].f=0;
				sm[i].num=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
