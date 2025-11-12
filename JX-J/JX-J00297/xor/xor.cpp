#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, a[maxn], sum[maxn], k, ans;
int main() {
	freopen("xor5.in", "r", stdin);
	freopen("xor5.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(!k) {
		for(int i = 1; i <= n; i ++) {
			if(!a[i]) ans ++;
		}
		cout << ans;
		return 0;
	}
	if(k == 1) {
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 1) ans ++;
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] xor a[i];
	for(int i = 1; i <= n; i ++) {
		if(a[i] == k) ans ++;
	}
	cout << ans;
	return 0;
}
