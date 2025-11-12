#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300],b[300],cnt,mc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long num=n*m;
	for(int i=1;i<=num;i++) scanf("%lld",&a[i]);
	long long x=a[1];
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--) b[++cnt]=a[i];
	for(int i=1;i<=cnt;i++) if(b[i]==x) mc=i;
	long long l=(mc-1)/n+1,h;
	if(l%2==1) h=mc - ( n * ( l - 1 ) );
		else h=n - ( mc - ( n * ( l - 1 ) ) ) + 1;
	printf("%lld %lld",l,h);
	return 0;
}
