#include<bits/stdc++.h>
using namespace std;
const int N=5020;
long long a[N],n,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==3)
	{
		int maxx=max({a[1],a[2],a[3]});
		if(a[1]+a[2]+a[3]>2*maxx)
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}
