#include<queue>
#include<cstdio>
#include<string.h>
#include<algorithm>
//#define long long long long
using namespace std;
char s[10000];
long long a[10010];
long long b[10010];
long long c[10010];
long long mod = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	scanf("%s",s);
	long long i;
	for(i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i = 1;i <= n;i++)
	{
		c[i] = s[i - 1] - '0';
	}
	for(i = 1;i <= n;i++)
	{
		b[i] = i;
	}
	long long ans = 0;
	do
	{
		//long long i;
		long long sum1 = 0;
		long long sum2 = 0;
		for(i = 1;i <= n;i++)
		{
			if(sum1 >= a[b[i]])
			{
				sum1++;
				continue;
			}
			if(!c[i])
			{
				sum1++;
				continue;
			}
			sum2++;
		}
		if(sum2 >= m)	ans++;
		ans %= mod;
	}while(next_permutation(b + 1,b + 1 + n));
	printf("%lld",ans);
	return 0;
}
