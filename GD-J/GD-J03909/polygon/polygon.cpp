#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
ll a[5010];
ll mod=998244353;
void dfs(ll x,ll num,ll maxn,ll sum){
	if(x>n){
		if(num>=3)
			if(maxn*2<sum)
				ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,num,maxn,sum);
	dfs(x+1,num+1,max(maxn,a[x]),sum+a[x]);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,-1e9,0);
	cout<<ans;
	return 0;
}
