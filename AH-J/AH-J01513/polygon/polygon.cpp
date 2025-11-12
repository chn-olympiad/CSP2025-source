#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=5e3+5;
LL n,a[N],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",a+i);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(sum>(a[n]*2)) printf("1");
	else printf("0");
	return 0;
}
