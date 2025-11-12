#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
ll a[N],n,ans;
void dfs(int t,ll maxn,ll s,ll m)
{
	if(m>=3&&s>maxn*2) ans++;
	for(int i=t+1;i<=n;i++) dfs(i,max(maxn,a[i]),s+a[i],m+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(0,0,0,0);
	printf("%lld",ans%998244353);
}
