#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5000+10;
ll n,cnt,a[N];
void dfs(ll sum,ll maxn,ll pre){
	if(sum>maxn*2) cnt++;
	for(ll i=pre+1;i<=n;i++) dfs(sum+a[i],max(maxn,a[i]),i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(0,0,0);
	printf("%lld",cnt%998244353);
	return 0;
}
