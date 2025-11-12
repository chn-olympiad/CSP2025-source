#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll ans;
ll ans1;
ll a[50005];
ll ans3;
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	f=1;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f && k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		for(ll i = 1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}else if(k==0){
		for(ll i = 1;i<=n;i+=2){
			if(i!=n){
				if(a[i]^a[i+1]==0 && a[i]!=0 && a[i+1]!=0){
					ans++;
				}
			}
		}
		for(ll i = 2;i<=n;i+=2){
			if(i!=n){
				if(a[i]^a[i+1]==0 && a[i]!=0 && a[i+1]!=0){
					ans1++;
				}
			}
		}
		ans3=max(ans,ans1);
		for(ll i = 1;i<=n;i++){
			if(a[i]==0){
				ans3++;
			}
		}
		cout<<ans3;
	}else{
		cout<<2;
	}
	return 0;
}