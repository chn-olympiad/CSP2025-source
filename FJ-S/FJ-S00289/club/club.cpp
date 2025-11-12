#include<bits/stdc++.h>
#define N 20010
using namespace std;
int n,t,ans,c1,c2,c3,maxf;
struct node{
	int a,b,c,chab,chabc,chac;
}f[N];
int minc1=0,minc2=0,mincw1,mincw2;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		c1=0,c2=0,c3=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&f[j].a,&f[j].b,&f[j].c);
			maxf=max(f[j].a,max(f[j].b,f[j].c));
			f[j].chab=f[j].b-f[j].a,f[j].chabc=f[j].c-f[j].b,f[j].chac=f[j].c-f[j].a;
			if(maxf==f[j].a)
			{
				c1++;
			}
			else if(maxf==f[j].b)
			{
				c2++;
			}
			else
			{
				c3++;
			}
			ans+=maxf;
		}
		minc1=0,minc2=0;
		printf("%d",ans);
	}
	return 0;
}
