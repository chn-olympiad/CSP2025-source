#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 998244353;
typedef long long ll;
//f[i]=

ll n, a[N], ans;

void dfs(int t, ll s, ll mx, ll k){ // t:number, s:sum, mx:max 
	if (t == n) {
		if(s > mx)ans++;
		return;
	}
	if (n-k < 3) return;
	dfs(t+1, s, mx, k+1);//buxuan
	for (int i = t; i <= n; i++) {
		dfs(t+i, s+a[i], max(mx, a[i]), k);
	} 
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 3) {
		cout << 0;
		return 0;
	}
	
	dfs(1, 0, 0, 0);
	cout << ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
