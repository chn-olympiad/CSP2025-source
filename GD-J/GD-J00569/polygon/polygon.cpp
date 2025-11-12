#include<bits/stdc++.h>

using namespace std;
long long n,a[5005],x,y,z;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==3)
	{
		x=a[1],y=a[2],z=a[3];
		if(x>y) swap(x,y);if(x>z) swap(x,z);if(y>z) swap(z,y);
		if(x+y>z) cout<<1;
	}
	


	return 0;
}
