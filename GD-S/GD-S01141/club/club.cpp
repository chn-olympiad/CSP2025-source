#include<bits/stdc++.h>
using namespace std;
int t,n,o1,o2,o3,ans,p[100005],s,bz[100005];
struct www{
	int a,b,c;
}e[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		o1=0;
		o2=0;
		o3=0;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&e[j].a,&e[j].b,&e[j].c);
			if(e[j].a>=e[j].b&&e[j].a>=e[j].c)
			{
				o1++;
				ans+=e[j].a;
				bz[j]=1;
			}
			else if(e[j].b>=e[j].a&&e[j].b>=e[j].c)
			{
				o2++;
				ans+=e[j].b;
				bz[j]=2;
			}
			else if(e[j].c>=e[j].a&&e[j].c>=e[j].b)
			{
				o3++;
				ans+=e[j].c;
				bz[j]=3;
			}
		}	
		if(o1<=n/2&&o2<=n/2&&o3<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		s=0;
		if(o1>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(bz[j]==1)
				{
					s++;
					p[s]=max(e[j].b,e[j].c)-e[j].a;
				}
			}
			sort(p+1,p+s+1,cmp);
			for(int j=1;j<=o1-n/2;j++)
				ans+=p[j];
		}
		else if(o2>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(bz[j]==2)
				{
					s++;
					p[s]=max(e[j].a,e[j].c)-e[j].b;
				}		
			}
			sort(p+1,p+s+1,cmp);
			for(int j=1;j<=o2-n/2;j++)
				ans+=p[j];
		}
		else if(o3>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(bz[j]==3)
				{
					s++;
					p[s]=max(e[j].a,e[j].b)-e[j].c;
				}
			}
			sort(p+1,p+s+1,cmp);
			for(int j=1;j<=o3-n/2;j++)
				ans+=p[j];
		}
		cout<<ans<<endl;
	}
}
