#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=998244353;
ll n,a[5010],ans=0;
inline ll add(ll x,ll y)
{
	ll res=0;
	for(ll i=x;i<=y;i++)res+=a[i];
	return res;
}
inline void dfs(ll x)
{
	if(x>=n-1)return;
	for(ll i=x;i<n-1;i++)for(ll j=i+2;j<=n;j++)if(add(x,j)>2*a[j])
	{
		sum=(sum+1)%P;
	}
	ans=(ans+sum)%P;
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
