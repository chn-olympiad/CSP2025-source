#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	long long m[5];
	int f[5];
}a[100005];

bool cmp(node n1,node n2)
{
	return n1.m[1]+n2.m[2]>n2.m[1]+n1.m[2];
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int maxn=0,minn=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].m[1],&a[i].m[2],&a[i].m[3]);
			a[i].f[1]=1;
			a[i].f[2]=2;
			a[i].f[3]=3;
			if(a[i].m[3]>a[i].m[2])
			{
				swap(a[i].m[3],a[i].m[2]);
				swap(a[i].f[3],a[i].f[2]);
			}
			if(a[i].m[2]>a[i].m[1])
			{
				swap(a[i].m[1],a[i].m[2]);
				swap(a[i].f[1],a[i].f[2]);
			}
			if(a[i].m[3]>a[i].m[2])
			{
				swap(a[i].m[3],a[i].m[2]);
				swap(a[i].f[3],a[i].f[2]);
			}
		}
		sort(a+1,a+n+1,cmp);
		int js[3]={0};
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				int mt,ft;
				mt=a[i].m[j],ft=a[i].f[j];
				if(js[ft-1]<(n/2)) 
				{
					js[ft-1]++;
					ans+=mt;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
