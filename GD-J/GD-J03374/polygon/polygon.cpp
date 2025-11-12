#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5100;
const LL P=998244353;
int a[N],s[N],n;

LL qpow(LL a,LL b)
{
	LL res=0;
	for(;b;b>>=1,a=a*a%P)if(b&1)res=(res+a)%P;
	return res;
}
LL dfs(int x,int sum,int aim)
{
	if(x==0)return sum>aim;
	if(sum>aim)
	{
		return qpow(2ll,1ll*x);
	}
	if(s[x]<=aim-sum)return 0ll;
	return (dfs(x-1,sum+a[x],aim)+dfs(x-1,sum,aim))%P;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(s,0,sizeof(s));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	LL ans=0;
	for(int i=3;i<=n;i++)ans=(ans+dfs(i,0,a[i]*2))%P;
	printf("%lld\n",ans);
	return 0;
}
