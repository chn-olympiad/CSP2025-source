#include<bits/stdc++.h>
using namespace std;
long long n,s,t,tt,ttt,d[100100],ji;
struct w{
	long long x,y;
}f[100100];
bool ww(w a,w b)
{
	return a.y<b.y;
}
main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	scanf("%lld",&T);
	while(T--)
	{
		s=0;
		t=tt=ttt=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
		{
			long long a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			if(a>=b&&a>=c)
				s=s+a,t++,f[i].x=1,f[i].y=max(b-a,c-a);
			else
			{
			if(b>=a&&b>=c)
				s=s+b,tt++,f[i].x=2,f[i].y=max(a-b,c-b);
			else
			if(c>=b&&c>=a)
				s=s+c,ttt++,f[i].x=3,f[i].y=max(b-c,a-c);
			}
		}
		if(t<=n/2&&tt<=n/2&&ttt<=n/2)
		{
			printf("%lld\n",s);
			continue;
		}
		sort(f+1,f+n+1,ww);
		long long ss=0;
		if(t>n/2)
			ji=1,ss=t-n/2;
		if(tt>n/2)
			ji=2,ss=tt-n/2;
		if(ttt>n/2)
			ji=3,ss=ttt-n/2;
		for(long long i=n;i>=1&&ss>0;i--)
		if(f[i].x==ji)
		{
			ss--;
			s=s+f[i].y;
		}
		printf("%lld\n",s);
	}
}
