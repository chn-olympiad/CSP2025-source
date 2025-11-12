#include<bits/stdc++.h>
using namespace std;
long long int t,n,a[5],sum[5];
struct k
{
	long long int zd,dd,z,a,b,c,l[4];
}o[100005];
bool vis[100005];
bool bb(k a,k b)
{
	return a.z>b.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%lld",&n);
			for(int i=1;i<=n;i++)
		{
		scanf("%lld%lld%lld",&o[i].a,&o[i].b,&o[i].c);
		if(o[i].a>=o[i].b&&o[i].c<=o[i].a)
		{
			o[i].zd=1;
			if(o[i].b>=o[i].c)	
			{
				o[i].dd=2;
				o[i].z=o[i].a-o[i].b;
			}
			else
			{
				o[i].dd=3;
				o[i].z=o[i].a-o[i].c;
			}
		}else if(o[i].b>=o[i].a&&o[i].c<=o[i].b)
		{
			o[i].zd=2;
			if(o[i].a>=o[i].c)	
			{
				o[i].dd=1;
				o[i].z=o[i].b-o[i].a;
			}
			else
			{
				o[i].dd=3;
				o[i].z=o[i].b-o[i].c;
			}
		}
		if(o[i].c>=o[i].a&&o[i].b<=o[i].c)
		{
			o[i].zd=3;
			if(o[i].a>=o[i].b)	
			{
				o[i].dd=1;
				o[i].z=o[i].c-o[i].a;
			}
			else
			{
				o[i].dd=2;
				o[i].z=o[i].c-o[i].b;
			}
		}
		o[i].l[1]=o[i].a;
		o[i].l[2]=o[i].b;
		o[i].l[3]=o[i].c;
		}
	sort(o+1,o+n+1,bb);
	for(int i=1;i<=n;i++)
	{
		if(a[o[i].zd]<n/2){sum[o[i].zd]+=o[i].l[o[i].zd];a[o[i].zd]++;}
		else {sum[o[i].dd]+=o[i].l[o[i].dd];a[o[i].dd]++;}
	}
	printf("%lld\n",sum[1]+sum[2]+sum[3]);
	sum[1]=0;
	sum[2]=0;
	sum[3]=0;
	a[1]=0;
	a[2]=0;
	a[3]=0;
	}
	return 0;
}
