#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,k,a[500005],ans;
map<ll,ll> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	if(mp[1]==n&&k==0){
		cout<<n/2;
		return 0;
	}else if(mp[1]==n&&k==1){
		cout<<n;
		return 0;
	}else if(mp[0]==n&&k==0){
		cout<<n;
		return 0;
	}else if(mp[0]==n&&k==1){
		cout<<0;
		return 0;
	}else if(k==0){
		ll f=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				f=0;
			}else{
				f++;
				if(f==2){
					ans++;
					f=0;
				}
			}
		}
		cout<<ans;
		return 0;
	}else{
		cout<<mp[1];
		return 0;
	}
	return 0;
}