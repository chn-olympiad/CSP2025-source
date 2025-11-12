#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e8 + 100, mod = 998244353; 
ll n, ans;
ll a[N];
void dfs(ll u, ll l, ll c, ll maxx, bool st){
	if(c >= 3 && l > (2 * maxx) && st){
		ans++;
		ans %= mod; 
	}
	if(u == n + 1){
		return;
	}
	dfs(u + 1, l + a[u], c + 1, max(maxx, a[u]), true);
	dfs(u + 1, l, c, maxx, false);
	return;
}
int main(){
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0, 0, true);
	cout << ans;
	return 0;	
}
