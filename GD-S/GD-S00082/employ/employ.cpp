#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll mod=998244353;
ll fac[N],inv[N],ans;
int n,m,a[N],p[N];
char st[N];
bool vis[N];
ll fpm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=fpm(fac[N-1],mod-2);
	for(int i=N-1;i;i--) inv[i-1]=inv[i]*i%mod;
}
void solve(int k)
{
	if(k>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(st[i]=='0'||a[p[i]]<=cnt) ++cnt;
		if(n-cnt>=m) ++ans;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			p[k]=i;
			solve(k+1);
			vis[i]=false;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	scanf("%d%d%s",&n,&m,st+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	solve(1);
	printf("%lld",ans);
	return 0;
}
