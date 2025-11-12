#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans;
void dfs(ll q,ll x,ll sum,ll ma){
	if(sum>ma*2)ans++;
	if(x>n)return;
	for(int i=q;i<=n;i++)
		dfs(i+1,x+1,sum+a[i],max(ma,a[i]));
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,1,0,0);
	printf("%lld",ans);
	return 0;
}
