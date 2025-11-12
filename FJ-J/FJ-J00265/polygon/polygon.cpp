#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l[5050],ans = 0,m = 0,mod = 998244353,b[5050],f;
void dfs(ll x,ll y) {
	if (y == 3) return;
	for (ll i = f;i < x;i++){
		if (m - l[i] > 2 * l[x]){
			ll c = f;
			m -= l[i],f = i + 1,ans++,ans %= mod;
			dfs(x,y - 1);
			f = c,m += l[i];
		 }
	 }
 }
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (ll i = 1;i <= n;i++) cin>>l[i];
	sort(l + 1,l + 1 + n);
	for (ll i = 1;i <= n;i++) b[i] = b[i - 1] + l[i];
	for (ll i = 3;i <= n;i++){
		f = 1,m = b[i];
		if (b[i] > 2 * l[i]) {ans++;dfs(i,i);}
	 }
	cout<<ans;
	return 0;
 }
