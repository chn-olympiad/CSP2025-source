#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
long long n,a[N][4],d[N];
long long ans;
long long c1,c2,c3;
long long c[N],cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=c1=c2=c3=cnt=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				ans+=a[i][1];
				d[i]=1;
				c1++;
			}
			else if(a[i][2]>=a[i][3])
			{
				ans+=a[i][2];
				d[i]=2;
				c2++;
			}
			else 
			{
				ans+=a[i][3];
				d[i]=3;
				c3++;
			}
		}
		if(c1>n/2)
		{
			int num=c1-n/2;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==1)
				{
					cnt++;
					c[cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
			}
			sort(c+1,c+cnt+1);
			for(int i=1;i<=num;i++)ans-=c[i];
		}
		else if(c2>n/2)
		{
			int num=c2-n/2;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==2)
				{
					cnt++;
					c[cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
			}
			sort(c+1,c+cnt+1);
			for(int i=1;i<=num;i++)ans-=c[i];
		}
		else if(c3>n/2)
		{
			int num=c3-n/2;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==3)
				{
					cnt++;
					c[cnt]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
				}
			}
			sort(c+1,c+cnt+1);
			for(int i=1;i<=num;i++)ans-=c[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
