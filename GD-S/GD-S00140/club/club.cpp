//T1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,cnt[4],a[100500][4];
void dfs(ll i,ll sum){
	if(i>n){
		if(sum>ans){
			ans=sum;
		}
		return;
	}
	for(ll j=1;j<=3;j++){
		if(cnt[j]==n/2){
			continue;
		}
		cnt[j]++;
		dfs(i+1,sum+a[i][j]);
		cnt[j]--;
	}
	return;
}
void solve(){
	ans=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--){
		solve();
	}
	return 0;
}
