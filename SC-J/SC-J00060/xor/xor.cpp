#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n,k,a;
vector<ll> v(1,0);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a;
		v.push_back(ll(a^v[i-1]));
	}
	a=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			if(ll(v[i]^v[j])==k){
				a++,i=j-1;
				break;
			}
		}
	}
	cout<<a;
	return 0;
}