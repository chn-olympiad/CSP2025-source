#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0;
ll n;
ll a[5001];
ll read(){
	char c = getchar();
	ll ans = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar(); 
	return ans;
}
void dfs(ll x, ll mx, ll sum, ll m){
	if (x == n + 1){
		if (mx * 2 < sum && m >= 3) ans++;
		return;
	}
	dfs(x + 1, max(mx, a[x]), sum + a[x], m + 1);
	dfs(x + 1, mx, sum, m);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) a[i] = read();
	dfs(1, 0, 0, 0);
	printf("%lld", ans);
	return 0;
}
