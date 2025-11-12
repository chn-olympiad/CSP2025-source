#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	long long num=0;
	for(int i=1;i<=n*m;i++)num+=a[i]>=a[1];
	long long t=(num-1)/n+1,tt=(num-1)%n+1;
	if(t&1) printf("%lld %lld",t,tt);
	else printf("%lld %lld",t,n-tt+1);
	return 0;
}
