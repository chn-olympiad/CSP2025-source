#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans = 0;
int a[5001];
int dp = 0, add = 0, target = 0; 
void dfs(int l, int r) {
	add += a[r];
	dp++;
	if(add >= target) {
		dp--;
		add -= a[r];
		cout << "111" << endl;
		return;
	}
	if(dp > 1) ans++;
	for(int i = l; i < r; i++) {
		dfs(l, i);
	}
	dp--;
	add -= a[r];
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 3; i <= n; i++) {
		target = a[i];
		dfs(1, i);
		dp = 0, add = 0, target = 0; 
	}
	cout << ans % 998244353;
	return 0;
}
