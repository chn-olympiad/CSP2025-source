#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll N=5005;
ll n,a[N],s[N],ans,v[N],b[N];
map<ll,ll> mp;
void teshu(){
	for(ll i=1;i<=n;i++){
		ll cnt=0;
		for(ll j=n-i-1;j>=1;j--){
			cnt+=j;
		}
		ans+=cnt;
		ans%=998244353;
	}
	cout<<ans%998244353;
}
void dfs(ll k,ll cnt,ll m,ll x){
	if(k==m+1){
		ll mx=-1e18;
		for(ll i=1;i<=m;i++){
			mx=max(mx,b[i]);
		}
		if(cnt>mx*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(ll i=x+1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			b[k]=a[i];
			dfs(k+1,cnt+a[i],m,i);
			v[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		mp[a[i]]++;
	}
	if(mp[1]==n){
		teshu();
		return 0;
	}
	for(ll i=2;i<=n;i++){
		fill(v+1,v+n+1,0);
		dfs(1,0,i,0);
	}
	cout<<ans%998244353;
	return 0;
}