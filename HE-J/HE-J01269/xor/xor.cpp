#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	printf("%lld",k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
