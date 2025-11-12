#include<bits/stdc++.h>
#define AC return 0
#define ll unsigned long long
const int MAXN = 5005;
const int MOD = 998244353;
const int MAXD = 1e8 + 3e7;
using namespace std;

int n = 3, a[MAXN] = {0}, cnt = 0, ncnt = 0;

void dfs (ll current, int current_max, int num, int sum) {
	ncnt++;
	if (ncnt >= MAXD) return; // RP++
	if (num >= n) return;
	if (sum >= 3) if (current > (ll)(2 * current_max)) cnt++, cnt %= MOD;
	for (int i=num+1; i<n; i++) dfs(current+a[i], a[i], i, sum+1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n < 4) {
		cout << "1\n";
		AC;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) dfs(a[i], a[i], i, 1);
	cout << cnt;
	AC;
}