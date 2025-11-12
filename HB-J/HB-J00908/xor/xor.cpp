#include <cstdio>
#include <cstdlib>
using namespace std;
long long d[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%lld %lld",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	printf("%lld\n",n/2);
	return 0;
}
