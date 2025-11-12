#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n, a[5005], b[5005], ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			int maxn = a[i];
			for (int k = i; k <= j; k++){
				maxn = max(maxn, a[k]);
			}
			if (b[j] - b[i - 1] > 2 * maxn) ans++;
		}
	}
	cout << ans % MOD;
	return 0;
}
