#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<ll> a(n+1);
	vector<vector<ll>> b(10010,vector<ll>(10010));
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=0;i<s.size();i++){
		if(s[i]=='1') ans++;
	}
	cout<<ans;
	return 0;
}

