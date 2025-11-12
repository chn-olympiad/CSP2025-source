#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll T;
ll n;
ll const maxn=100000;
ll a[maxn+1][4];
ll bi[maxn+1];
ll ci[maxn+1];
ll ss[maxn+1];
void solve(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	for(ll i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			bi[i]=1;
			if(a[i][2]>a[i][3]){
				ci[i]=2;
			}
			else{
				ci[i]=3;
			}
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			bi[i]=2;
			if(a[i][1]>a[i][3]){
				ci[i]=1;
			}
			else{
				ci[i]=3;
			}
		}
		else{
			bi[i]=3;
			if(a[i][1]>a[i][2]){
				ci[i]=1;
			}
			else{
				ci[i]=2;
			}
		}
	}
	ll g[4]={0,0,0,0};
	for(ll i=1;i<=n;i++){
		g[bi[i]]++;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=a[i][bi[i]];
	}
	if(g[1]<=n/2&&g[2]<=n/2&&g[3]<=n/2){
		printf("%lld\n",ans);
		return;
	}
	for(ll i=1;i<=n;i++){
		ss[i]=a[i][bi[i]]-a[i][ci[i]];
	}
	vector<ll>sp;
	ll pp=0;
	if(g[1]>n/2){
		pp=1;
	}
	if(g[2]>n/2){
		pp=2;
	}
	if(g[3]>n/2){
		pp=3;
	}
	for(ll i=1;i<=n;i++){
		if(bi[i]==pp){
			sp.push_back(ss[i]);
		}
	}
	sort(sp.begin(),sp.end());
	for(ll i=0;i<g[pp]-n/2;i++){
		ans-=sp[i];
	}
	printf("%lld\n",ans);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		solve();
	}
	
	
	return 0;
}
