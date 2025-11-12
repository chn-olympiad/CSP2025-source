#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e4+10;
const ll mod=998244353;
ll a[maxn],n,ans;
ll t(ll sum,ll y,ll i){
	for(ll j=y+1;j<=i-1;j++){
		if(sum+a[j]>a[i]){
			ans%=mod;
			ans++;
			ans%=mod;
		}
		t(sum+a[j],j,i);
	}
	return 0;
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
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=3;i--){
		for(ll j=1;j<i-1;j++){
			for(ll k=j+1;k<=i-1;k++){
				if(a[j]+a[k]>a[i]){
					ans%=mod;
					ans++;
					ans%=mod;
				}
				t(a[j]+a[k],k,i);
			}
		}
	}
	cout<<ans%mod;
	
	
	return 0;
} 
