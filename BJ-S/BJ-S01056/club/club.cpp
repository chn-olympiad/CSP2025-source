#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, a[N][4], _[N], ans = 0, __[4];
void dfs(int cur) {
	if (cur > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i][_[i]];
		ans = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		 _[cur] = i;
		 __[i]++;
		 if (__[i] <= n / 2) dfs(cur + 1);
		 __[i]--;
	}
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];
	ans = 0;
    dfs(1);
	cout << ans << '\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solve();
    return 0;
}