#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll t,n,a[N],b[N],c[N],vis[N];
ll ans[N],maxn=-1e18;
void dfs(ll step){
	if(step==n+1){
		ll sum=0;
		for(ll i=1;i<=n;++i)sum+=ans[i];
		maxn=max(maxn,sum);
	}
	for(ll i=step;i<=n;++i){
		ans[step]=a[i];
		dfs(i+1);
		ans[step]=b[i];
		dfs(i+1);
		ans[step]=c[i];
		dfs(i+1);
	}
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		maxn=-1e18;
		cin>>n;
		for(ll i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i];
		dfs(1);
		cout<<maxn<<"\n";
	}
	return 0;
}
