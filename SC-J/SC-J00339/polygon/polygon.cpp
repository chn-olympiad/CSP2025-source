#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2.5e7 + 10, MAXN = 5010;
const int MOD = 998244353;
int a[MAXN], pre[MAXN], f[MAXM];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	f[0] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int k = a[i] + 1; k <= pre[i] - a[i]; k++){
			ans = (ans + f[k]) % MOD;
		}
		for (int k = pre[i]; k >= a[i]; k--){
			f[k] = (f[k] + f[k - a[i]]) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}