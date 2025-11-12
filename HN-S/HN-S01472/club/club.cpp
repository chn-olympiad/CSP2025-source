#include<bits/stdc++.h>
using namespace std;
int t,n,amax,amaxs,amin,amins,amiddle,amiddles,people[4],ans;
struct a
{
	int a;
	int b[4];
	int max;
	int maxs;
	int min;
	int mins;
	int middle;
	int middles;
	int u;
	int c1;
	int c2;
}a[200000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int t1=1;t1<=t;t1++)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=3;i++)
		{
			people[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			amaxs=0;
			amins=10000000;
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i].a);
				a[i].b[j]=a[i].a;
				if(a[i].a>amaxs)
				{
					amax=j;
					amaxs=a[i].a;
				}
				else if(a[i].a<amins)
				{
					amin=j;
					amins=a[i].a;
				}
			}
			a[i].maxs=amaxs;
			a[i].mins=amins;
			a[i].max=amax;
			a[i].min=amin;
			for(int k=1;k<=3;k++)
			{
				if(k!=a[i].max&&k!=a[i].min)
				{
					amiddle=k;
					amiddles=a[i].b[k];
				}
			}
			a[i].middle=amiddle;
			a[i].middles=amiddles;
			a[i].c1=amaxs-amiddles;
			a[i].c2=amiddles-amins;
			a[i].u=0;
//			printf("%d %d %d %d %d %d\n",a[i].maxs,a[i].middles,a[i].mins,a[i].c1,a[i].c2,a[i].u);
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i].c1<a[j].c1)
				{
					swap(a[i],a[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
//			printf("1:%d %d %d %d %d %d\n",a[i].maxs,a[i].middles,a[i].mins,a[i].c1,a[i].c2,a[i].u);
			if(people[a[i].max]<n/2)
			{
				ans+=a[i].maxs;
				people[a[i].max]++;
				a[i].u=1;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i].c2<a[j].c2||a[i].u)
				{
					swap(a[i],a[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
//			printf("2:%d %d %d %d %d %d\n",a[i].maxs,a[i].middles,a[i].mins,a[i].c1,a[i].c2,a[i].u);
			if(a[i].u==0)
			{
				if(people[a[i].middle]<n/2)
				{
					ans+=a[i].middles;
					people[a[i].middle]++;
					a[i].u=1;
				}
				else
				{
					ans+=a[i].mins;
					people[a[i].min]++;
					a[i].u=1;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
