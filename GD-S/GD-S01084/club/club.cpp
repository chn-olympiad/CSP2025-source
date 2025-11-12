#include<bits/stdc++.h>
using namespace std;
long long T,n,aa[5005][3],size,sizee,sizeee,y=0;
struct s{
	long long a,b,c,d;
}a[100005];
bool cmp(s a,s b)
{
	if(a.d!=b.d)return a.d>b.d;
	int h1=max(a.a,max(a.b,a.c)),h2=min(a.a,min(a.b,a.c)),h3=a.a+a.b+a.c-h2-h1;
	int g1=max(b.a,max(b.b,b.c)),g2=min(b.a,min(b.b,b.c)),g3=b.a+b.b+b.c-h2-h1;
	if(h1!=g1)return h1>g1;
	if(h3!=g3)return h3>g3;
	return h2>g2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		size=sizee=sizeee=y=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			a[i].d=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a==0||a[i].b==0||a[i].c==0)a[i].d=a[i].d*2-a[i].a-a[i].b-a[i].c;
			else a[i].d=a[i].d*3-a[i].a-a[i].b-a[i].c;
		}
		sort(a+1,a+1+n,cmp);
		int h=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				if(size<n/2)
				{
					aa[++size][0]=i;
				}
				else
				{
					if(a[i].c>a[i].b)aa[++sizeee][2]=i;
					else aa[++sizee][1]=i;
				}
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				if(sizee<n/2)
				{
					aa[++sizee][1]=i;
				}
				else
				{
					if(a[i].a>a[i].c)aa[++size][0]=i;
					else aa[++sizeee][2]=i;
				}
			}
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b)
			{
				if(sizeee<n/2)
				{
					aa[++sizeee][2]=i;
				}
				else
				{
					if(a[i].a>a[i].b)aa[++size][0]=i;
					else aa[++sizee][1]=i;
				}
			}
		}
		for(int i=1;i<=size;i++)
		{
			y=y+a[aa[i][0]].a;
		}
		for(int i=1;i<=sizee;i++)
		{
			y=y+a[aa[i][1]].b;
		}
		for(int i=1;i<=sizeee;i++)
		{
			y=y+a[aa[i][2]].c;
		}
		printf("%lld\n",y);
	}
	
	return 0;
}
