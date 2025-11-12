#include<bits/stdc++.h>
using namespace std;;
const int O=1e5+25;
int T,N,Sum=0,Asum=0,Bsum=0,Csum=0,ABsum=0,BCsum=0,ACsum=0,ABCsum=0;
struct Su
{
	int a,b,c;
	int al=-1,bl=-1,cl=-1;
}a[O];
bool AP(Su x,Su y)
{
	if (x.al==1&&y.al==1)
		return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
	return x.al>y.al;
}
bool BP(Su x,Su y)
{
	if (x.bl==1&&y.bl==1)
		return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
	return x.bl>y.bl;
}
bool CP(Su x,Su y)
{
	if (x.cl==1&&y.cl==1)
		return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);
	return x.cl>y.cl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		Sum=0,Asum=0,Bsum=0,Csum=0;
		ABsum=0,ACsum=0,BCsum=0,ABCsum=0;
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].al=-1,a[i].bl=-1,a[i].cl=-1;
			if (a[i].a>max(a[i].b,a[i].c))
			{
				Asum++,a[i].al=1;
				Sum+=a[i].a;
				continue;
			}
			if (a[i].b>max(a[i].a,a[i].c))
			{
				Bsum++,a[i].bl=1;
				Sum+=a[i].b;
				continue;
			}
			if (a[i].c>max(a[i].a,a[i].b))
			{
				Csum++,a[i].cl=1;
				Sum+=a[i].c;
				continue;
			}
			if (a[i].a==a[i].b&&a[i].b==a[i].c)
			{
				ABCsum++,a[i].al=1,a[i].bl=1,a[i].cl=1;
				Sum+=a[i].a;
				continue;
			}
			if (a[i].a==a[i].b)
			{
				ABsum++,a[i].al=1,a[i].bl=1;
				Sum+=a[i].a;
				continue;
			}
			if (a[i].b==a[i].c)
			{
				BCsum++,a[i].bl=1,a[i].cl=1;
				Sum+=a[i].b;
				continue;
			}
			if (a[i].a==a[i].c)
			{
				ACsum++,a[i].al=1,a[i].cl=1;
				Sum+=a[i].a;
				continue;
			}
		}
		if (Asum<=N/2&&Bsum<=N/2&&Csum<=N/2)
		{
			printf("%d\n",Sum);
			continue;
		}
		if (Asum>N/2)
		{
			sort(a+1,a+N+1,AP);
			for(int i=1,j=Asum+ABsum+ACsum+ABCsum;j>N/2;i++,j--)
				Sum-=min(a[i].a-a[i].b,a[i].a-a[i].c);
			printf("%d\n",Sum);
			continue;
		}
		if (Bsum>N/2)
		{
			sort(a+1,a+N+1,BP);
			for(int i=1,j=Bsum+ABsum+BCsum+ABCsum;j>N/2;i++,j--)
				Sum-=min(a[i].b-a[i].a,a[i].b-a[i].c);
			printf("%d\n",Sum);
			continue;
		}
		if (Csum>N/2)
		{
			sort(a+1,a+N+1,CP);
			for(int i=1,j=Csum+ACsum+BCsum+ABCsum;j>N/2;i++,j--)
				Sum-=min(a[i].c-a[i].a,a[i].c-a[i].b);
			printf("%d\n",Sum);
			continue;
		}
	}
	return 0;
}
