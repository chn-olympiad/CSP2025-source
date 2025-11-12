#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e2+10,mod=998244353;
LL fac[N];
int s[N],c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c[i]);
	}
	if(m>n)
	{
		printf("0\n");
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	printf("%lld\n",fac[n]);
	return 0;
}
