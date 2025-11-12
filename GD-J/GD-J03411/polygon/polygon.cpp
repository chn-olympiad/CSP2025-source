#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
constexpr int MAXN = 5009, MOD = 998244353;
int n, ans, sum, cnt, mx, a[MAXN];
void solve1() {
	for(int i = 0; i < (1 << n); i++) {
		mx = sum = cnt = 0;
		for(int j = 0; j < n; j++) {
			if(!(1 & (i >> j))) continue;
			mx = max(mx, a[j]);
			sum += a[j];
			cnt++;
		}
		if(cnt < 3) continue;
		if(sum > 2 * mx) ans++;
	}
	cout << ans;
}
void solve2() {
	cout << 1;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a, a + n);
	if(n <= 20) solve1();
	else solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
