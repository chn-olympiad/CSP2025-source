#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,a[5005];
void dfs(ll i,ll p,ll maxn,ll cnt){
	if(p>=3&&cnt>2*maxn){
		ans++;
		ans=(ans+998244353ll)%998244353ll;
	}
	if(p>=n){
		return;
	}
	for(ll j=i+1;j<=n;j++){
		
		dfs(j,p+1,max(maxn,a[j]),cnt+a[j]);
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f==0ll) dfs(0ll,0ll,0ll,0ll);
	else{
		ll cnt=1;
		for(ll i=1;i<=n;i++) cnt=(cnt*2+998244353ll)%998244353ll;
		cout<<(cnt-1ll-n*(n-1)/2ll-n+998244353ll)%998244353ll;
		return 0;
	}
	cout<<(ans+998244353ll)%998244353ll;
	return 0;
} 