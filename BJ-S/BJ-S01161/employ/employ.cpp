#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	string s;
	cin>>n>>m>>s;
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}