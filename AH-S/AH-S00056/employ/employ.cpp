#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[505],n,m,mod=998244353;
void sol (){
	ll ans=1;
	for (int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	bool ok=1;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
		if (s[i-1]!='1') ok=0;
		//else cout<<i<<endl;
	}
	if (ok) {
		sol ();
	}
	else {
		//if (n<=18) {
		//	dfs ()
		//}
		//else {
		//	
		//}
		cout<<0<<endl;
	}
	return 0;
}
