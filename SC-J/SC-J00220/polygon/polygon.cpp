#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,MOD=998244353;
int n;
int a[N],ans;
bool flag[N];
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=1) return 0;
	return 1;
}
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res=res*x%MOD;
		x=x*x%MOD,y>>=1;
	}
	return res%MOD;
}
void check2()
{
	int maxx=0,sum=0;
	for(int i=1;i<=n;i++)
		if(flag[i]) sum+=a[i],maxx=max(maxx,a[i]);
	if(sum>2*maxx) ans++;
}
void dfs(int x,int tot)
{
	if(n-x+1+tot<3) return;
	if(x==n+1&&tot>=3)
	{
		check2();
		return;
	}
	flag[x]=1,dfs(x+1,tot+1),flag[x]=0,dfs(x+1,tot);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(check())
	{
		printf("%lld\n",((qpow(2,n)+MOD-1-n-n*(n-1)/2%MOD)%MOD+MOD)%MOD);
		return 0;
	}
	dfs(1,0),printf("%lld\n",ans);
	return 0;
}