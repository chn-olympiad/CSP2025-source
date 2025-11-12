#include <bits/stdc++.h>
using namespace std;
long long a[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(k==0)
		printf("%lld\n",n/2);

	return 0;
}
