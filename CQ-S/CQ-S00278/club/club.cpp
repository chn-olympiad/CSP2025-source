#include <bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
const LL N = 1e5 + 5;
LL n, ans, idx[4];
LL b[4][N];
PII a[N][4];
void solve() {
	ans = idx[1] = idx[2] = idx[3] = 0;
	cin >> n;
	for(LL i = 1; i <= n; i ++ ) {
		a[i][1].second = 1, a[i][2].second = 2, a[i][3].second = 3;
		cin >> a[i][1].first >> a[i][2].first >> a[i][3].first;
		sort(a[i] + 1, a[i] + 4);
		b[a[i][3].second][ ++ idx[a[i][3].second]] = a[i][3].first - a[i][2].first;
		ans += a[i][3].first;
	}
	for(LL i = 1; i <= 3; i ++ ) {
		sort(b[i] + 1, b[i] + idx[i] + 1);
		for(LL j = 1; j <= idx[i] - n / 2; j ++ ) ans -= b[i][j];
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	LL T;
	cin >> T;
	while(T -- ) solve();
	return 0;
}

//long long
