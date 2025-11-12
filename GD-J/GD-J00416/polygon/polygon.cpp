#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll N = 5e5 + 10, mod = 998244353;
ll a[N],n,s[N], ans = 0, vis[N];
void dfs(ll ma, ll ji, ll len, ll j){
	if(len >= 3) {
		ans = (ans + 1) % mod;
	}
	vis[j] = true;
	for(int i = j + 1; i <= n; i++){
		if((a[i] >= ma && !vis[i] && 2 * a[i] < ji + a[i]) || (len == 0)){
			vis[i] = true;
			dfs(a[i], ji + a[i], len + 1, i);
			vis[i] = false;
		}
	}
	return;
}
void solve(){
	cin >> n;
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	dfs(0, 0, 0, 0);
	cout << ans;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int t = 1;
	while(t--) solve();
	return 0;
}
