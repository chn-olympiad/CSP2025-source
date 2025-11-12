#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[114514],b,c,d;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",a+i);
	}
	b=a[1];
	sort(a+1,a+1+n*m);
	b=n*m-(lower_bound(a+1,a+1+n*m,b)-a)+1;
	c=(b-1)/n+1;
	d=(c-1)*n;
	if(c%2==1)
	{
		printf("%lld %lld\n",c,b-d);
	}
	else
	{
		printf("%lld %lld\n",c,n-(b-d)+1);
	}
	return 0;
}
