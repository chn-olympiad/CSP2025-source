#include<bits/stdc++.h> 
using namespace std;
int n;
struct P
{
	int a,b,c;
}p[100005];
int dp[100005][3];
inline bool cmp(P a,P b){return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ZZZ=1;ZZZ<=T;ZZZ++)
	{
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		}
		sort(p+1,p+1+n,cmp);
		int ps[3]={0,0,0};
		for(int i=1;i<=n;i++)
		{
			int a=p[i].a,b=p[i].b,c=p[i].b;
			if(a>b&&a>c&&ps[0]<(n/2)){ans+=a;ps[0]++;continue;}
			if(b>a&&b>c&&ps[1]<(n/2)){ans+=b;ps[1]++;continue;}
			if(c>a&&c>b&&ps[2]<(n/2)){ans+=c;ps[2]++;continue;}
			if(a==b&&a>c&&ps[0]<(n/2)&&ps[0]<=ps[1]){ans+=a;ps[0]++;continue;}
			if(a==b&&a>c&&ps[1]<(n/2)){ans+=b;ps[1]++;continue;}
			if(a==c&&a>b&&ps[0]<(n/2)&&ps[0]<=ps[2]){ans+=a;ps[0]++;continue;}
			if(a==c&&a>b&&ps[2]<(n/2)){ans+=c;ps[2]++;continue;}
			if(b==c&&b>a&&ps[1]<(n/2)&&ps[1]<=ps[2]){ans+=b;ps[1]++;continue;}
			if(b==c&&b>a&&ps[2]<(n/2)){ans+=c;ps[2]++;continue;}
			if(ps[0]=min(ps[2],min(ps[1],ps[0]))&&ps[0]<(n/2)){ans+=a;ps[0]++;continue;}
			if(ps[1]=min(ps[2],min(ps[1],ps[0]))&&ps[1]<(n/2)){ans+=b;ps[1]++;continue;}
			ans+=c;ps[2]++;continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
