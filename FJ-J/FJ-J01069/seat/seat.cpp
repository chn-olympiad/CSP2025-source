#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ss,xx=1,yy=0;
struct w{
	long long x,y;
}a[1010];
bool ww(w a,w b)
{
	return a.y>b.y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++)
	{
		a[i].x=i;
		scanf("%lld",&a[i].y);
	}
	sort(a+1,a+n*m+1,ww); 
	for(long long i=1;i<=n*m;i++)
		if(a[i].x==1)
		{
			s=i;
			break;
		}
	for(long long i=1;i<=m;i++)
	{
		if(s>n)
			s-=n;
		else
		{
			if(i%2)
			{
				printf("%lld %lld\n",i,s);
			}
			else
			{
				printf("%lld %lld\n",i,n-s+1);
			}
			return 0;
		}
	}
}
