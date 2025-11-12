#include<bits/stdc++.h>
using namespace std;
int n,t;
int a1[100002];
int a2[100002];
int a3[100002];
struct a11
{
	int yi,hao;
}ay[100002];
struct a12
{
	int er,hao;
}ae[100002];
struct a13
{
	int san,hao;
}as[100002];
bool cmp1(a11 x,a11 y)
{
	return x.yi>y.yi;
}
bool cmp2(a12 x,a12 y)
{
	return x.er>y.er;
}
bool cmp3(a13 x,a13 y)
{
	return x.san>y.san;
}
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int u=1;u<=t;u++)
	{
		ans=0;
		scanf("%d",&n);
		if(n==2)
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&ay[i].yi,&ae[i].er,&as[i].san);
				ay[i].hao=i;ae[i].hao=i;as[i].hao=i;
			}
			sort(ay+1,ay+n+1,cmp1);	
			sort(ae+1,ae+n+1,cmp2);
			sort(as+1,as+n+1,cmp3);
			int ji1=1,ji2=1,ji3=1;
			bool t1=1,t2=1,t3=1;
				if(ay[ji1].yi>=as[ji3].san&&ay[ji1].yi>=ae[ji2].er&&t1)
				{
					t1=0;
					ans+=ay[ji1].yi;
					if(ae[1].hao==ay[1].hao)
						ji2++;
					if(as[1].hao==ay[1].hao)
						ji3++;
					ji1=2;
				}
				else
				{
				if(ae[ji2].er>=as[ji3].san&&t2)
				{
					t2=0;
					ans+=ae[ji2].er;
					if(ae[1].hao==ay[1].hao)
						ji1++;
					if(ae[1].hao==as[1].hao)
						ji3++;
					ji2=2;
				}
				else
				{
					t3=0;
					ans+=as[ji3].san;
					if(ae[1].hao==as[1].hao)
						ji2++;
					if(ae[1].hao==as[1].hao)
						ji1++;
					ji3=2;
				}
				}
				if(ay[ji1].yi>=as[ji3].san&&ay[ji1].yi>=ae[ji2].er&&t1)
				{
					t1=0;
					ans+=ay[ji1].yi;
					if(ae[1].hao==ay[1].hao)
						ji2++;
					if(as[1].hao==ay[1].hao)
						ji3++;
					ji1=2;
				}
				else
				{
				if(ae[ji2].er>=as[ji3].san&&t2)
				{
					t2=0;
					ans+=ae[ji2].er;
					if(ae[1].hao==ay[1].hao)
						ji1++;
					if(ae[1].hao==as[1].hao)
						ji3++;
					ji2=2;
				}
				else
				{
					t3=0;
					ans+=as[ji3].san;
					if(ae[1].hao==as[1].hao)
						ji2++;
					if(ae[1].hao==as[1].hao)
						ji1++;
					ji3=2;
				}
				}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			}
			sort(a1+1,a1+1+n);
			for(int i=n;i>n/2;i--)
			{
				ans+=a1[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
