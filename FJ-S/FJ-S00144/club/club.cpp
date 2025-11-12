#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,m;
int x[MAXN],y[MAXN],z[MAXN],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n); m=n/2;
		x[0]=y[0]=z[0]=ans=0;
		for(int i=1;i<=n;i++)
		{
			int a,b,c; scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c)
			{
				x[0]++; ans+=a;
				x[x[0]]=min(a-b,a-c);
				continue;
			}
			if(b>=a&&b>=c)
			{
				y[0]++; ans+=b;
				y[y[0]]=min(b-a,b-c);
				continue;
			}
			if(c>=a&&c>=b)
			{
				z[0]++; ans+=c;
				z[z[0]]=min(c-a,c-b);
				continue;
			}
		}
		if(x[0]>m)
		{
			sort(x+1,x+x[0]+1);
			for(int i=1;i<=x[0]-m;i++)
				ans-=x[i];
		}
		else if(y[0]>m)
		{
			sort(y+1,y+y[0]+1);
			for(int i=1;i<=y[0]-m;i++)
				ans-=y[i];
		}
		else if(z[0]>m)
		{
			sort(z+1,z+z[0]+1);
			for(int i=1;i<=z[0]-m;i++)
				ans-=z[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
