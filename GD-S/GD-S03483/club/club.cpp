#include<iostream>
#include<algorithm>
using namespace std;
int t,n,sum1,sum2,sum3,ans,c1[100005],c2[100005],c3[100005];
struct node
{
	int a,b,c;
}p[100005];
bool cmp1(int x,int y)
{
	return max(p[x].b,p[x].c)-p[x].a>max(p[y].b,p[y].c)-p[y].a;
}
bool cmp2(int x,int y)
{
	return max(p[x].a,p[x].c)-p[x].b>max(p[y].a,p[y].c)-p[y].b;
}
bool cmp3(int x,int y)
{
	return max(p[x].b,p[x].a)-p[x].c>max(p[y].b,p[y].a)-p[y].c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf ("%d",&t);
	while(t--)
	{
		scanf ("%d",&n);
		sum1=sum2=sum3=ans=0;
		for (int i=1;i<=n;i++)
		{
			scanf ("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c)
				c1[++sum1]=i,ans+=p[i].a;
			else if(p[i].b>=p[i].a&&p[i].b>=p[i].c)
				c2[++sum2]=i,ans+=p[i].b;
			else
				c3[++sum3]=i,ans+=p[i].c;
		}
		if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2)
			printf ("%d\n",ans);
		if(sum1>n/2)
		{
			sort(c1+1,c1+1+sum1,cmp1);
			for (int i=1;i<=sum1-n/2;i++)
				ans+=max(p[c1[i]].b,p[c1[i]].c)-p[c1[i]].a;
			printf ("%d\n",ans);
		}
		if(sum2>n/2)
		{
			sort(c2+1,c2+1+sum2,cmp2);
			for (int i=1;i<=sum2-n/2;i++)
				ans+=max(p[c2[i]].a,p[c2[i]].c)-p[c2[i]].b;
			printf ("%d\n",ans);
		}
		if(sum3>n/2)
		{
			sort(c3+1,c3+1+sum3,cmp3);
			for (int i=1;i<=sum3-n/2;i++)
				ans+=max(p[c3[i]].b,p[c3[i]].a)-p[c3[i]].c;
			printf ("%d\n",ans);
		}
	}
	return 0;
}
