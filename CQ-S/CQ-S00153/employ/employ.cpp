#include<bits/stdc++.h>

using namespace std;
long long n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	if(m==n)
	{
		printf("0");
		return 0;
	}
	long long ans=1;
	for(long long i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	printf("%lld",ans);
	return 0;
}
