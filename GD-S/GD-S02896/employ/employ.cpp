#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[1000];
int c[1000];
bool v[1000];
int ans = 0;
long long t[1000];
int n, m;
void dfs(int x = 1, int y = 0){
	if (x == n + 1){
		if (y >= m){
			ans++;
			ans %= mod;
		}
		return;
	}
	if (y >= m){
		ans += t[n - (x - 1)];
//		cout << n - x + 1 << '\n';
		ans %= mod;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (v[i] == false){
			v[i] = true;
			dfs(x + 1, y + a[x] * (x - y - 1 < c[i]));
			v[i] = false;
		}
	}
	return;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	t[0] = 1;
	for (int i = 1; i <= n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
		t[i] = t[i - 1] * i % mod;
	}
	if (m == n){
		long long ans = 1;
		for (int i = 1; i <= n; i++){
			ans *= i;
			ans %= mod;
			if (c[i] == 0 || a[i] == 0){
				cout << 0 << '\n';
				return 0;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs();
	cout << ans << '\n';
	return 0;
}
