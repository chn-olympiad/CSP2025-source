#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,k,a,ans=0;
	cin>>n>>k;
	ll ps[n+5]={0};
	for(ll i=1;i<=n;i++){
		cin>>a;
		ps[i]=a^ps[i-1];
	}
	ll l=0;
		for(ll r=1;r<=n;r++){
			if((ps[r]^ps[l])==k || (ps[r]^ps[r-1])==k){
				ans++;
				l=r;
			}
		}
	cout<<ans;
    return 0;
}