#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e2+5;
long long n,m;
struct seat
{
	long long point;
	long long id_first;
}a[MAXN];
bool cmp(seat x,seat y)
{
	return x.point>y.point;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;++i)
	{
		scanf("%lld",&a[i].point);
		a[i].id_first=i;
	}
	sort(a+1,a+1+n*m,cmp);
	long long x=1,y=1,z=1;
	for(long long i=1;i<=n*m;++i,y+=z)
	{
		if(y<1) 
		{
			x++;
			y=1;
			z=-z;
		}
		if(y>n) 
		{
			x++;
			y=n;
			z=-z;
		}
		if(a[i].id_first==1) printf("%lld %lld",x,y);
	}
	return 0;
}
