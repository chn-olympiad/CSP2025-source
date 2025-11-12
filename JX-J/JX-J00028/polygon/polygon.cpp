#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5, mod = 998244353;
int n;
long long x;
long long a[maxn], ans, vis[maxn];
void find(long long num, long long ma, long long sum, long long now) {
	if(sum > ma * 2 && x == num) {
		ans = (ans + 1) % mod;
		return;
	}
	if(num > x) return;
	for(int i = now + 1; i <= n; i++) {
		find(num + 1, max(ma, a[i]), sum + a[i], i);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		for(int le = 3; le <= n - i + 1; le++) x = le, find(1, a[i], a[i], i);
	}
	cout << ans;
	return 0;
}
