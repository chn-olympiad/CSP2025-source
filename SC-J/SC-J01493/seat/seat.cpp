#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1100];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	int w=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int f;
	for(int i=1;i<=n*m;i++)
	{
		if(w==a[i])
		{
			f=i;
		}
	}
	int c;
	if(f%n!=0)
	{
		c=f/n+1;
	}
	else
	{
		c=f/n;
	}
	int d=f%n;
	if(d==0)
	{
		d=n;
	}
	int r;
	if(c%2==0)
	{
		r=n-d+1;
	}
	else
	{
		r=1+d-1;	
	}
	printf("%lld %lld",c,r);
	return 0;
}