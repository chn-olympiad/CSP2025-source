#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005],mod = 998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
	}ll ans = 0;
	if(n<=21){
		for(ll i = 1;i<=(1<<n)-1;i++){
			ll mx = 0;
			ll sum = 0;
			for(int j = 1;j<=n;j++){
				if((1<<(j-1))&i){
					sum+=a[j];
					mx = max(mx,a[j]);
				}
			}
			if(sum>2*mx){
				ans++;
			}
		}
	}
	else{
		for(int k = 1;k<=n-2;k++){
			for(int i = k;i>=1;i--){
				for(int j = 1;j<=i;j++){
					ans+=j;
				}
			}
		}
	}
	cout<<ans%mod;
}
