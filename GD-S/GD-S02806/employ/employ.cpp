#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return;
}

int main(){
	freopen("emlpoy.in","r",stdin);
	freopen("emlpoy.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
