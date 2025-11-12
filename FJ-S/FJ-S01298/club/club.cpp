#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
long long ans;
struct node{
	int s1,s2,s3;
}q[N];
//int f[N/2][3];
int ca[N],cb[N],cc[N];
int a,b,c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		a=0;b=0;c=0;ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&q[i].s1,&q[i].s2,&q[i].s3);
		}
		for(int i=1;i<=n;i++)
		{
			int T=max(q[i].s1,max(q[i].s2,q[i].s3));
			ans+=T;
			if(q[i].s1==T)
			{
				a++;
				ca[a]=min(q[i].s1-q[i].s2,q[i].s1-q[i].s3);
			}
			else if(q[i].s2==T)
			{
				b++;
				cb[b]=min(q[i].s2-q[i].s1,q[i].s2-q[i].s3);
			}
			else
			{
				c++;
				cc[c]=min(q[i].s3-q[i].s2,q[i].s3-q[i].s1);
			}
		}
		//printf("%d %d %d\n",a,b,c);
		if(a>n/2)
		{
			sort(ca+1,ca+a+1);
			int T=a-n/2;
			for(int i=1;i<=T;i++)
				ans-=ca[i];
		}
		else if(b>n/2)
		{
			sort(cb+1,cb+b+1);
			int T=b-n/2;
			for(int i=1;i<=T;i++)
				ans-=cb[i];
		}
		else
		{
			sort(cc+1,cc+c+1);
			int T=c-n/2;
			for(int i=1;i<=T;i++)
				ans-=cc[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//sarasa clip//
