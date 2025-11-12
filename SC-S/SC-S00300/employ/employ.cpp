#include <bits/stdc++.h>
#define ll long long 

using namespace std;
const ll mod = 998244353;
int n;
ll ans=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; ++i){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}