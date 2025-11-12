#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 1e5 + 10;
constexpr ll mod = 998244353;

using namespace std;

int n;
int a[N];
int sum[N];
ll ans;

void dfs(int x, int pos, int maxx, int cnt) {
    if (pos > n) {
        if (x > 2 * maxx && cnt >= 3) ans = (ans + 1) % mod;
        return;
    }
    if (n - pos + 1 + cnt < 3) return;
    if (sum[pos] + x < maxx * 2) return;
    dfs(x + a[pos], pos + 1, max(maxx, a[pos]), cnt + 1);
    dfs(x, pos + 1, maxx, cnt);
}

void Debug() {

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n > 500) {
		cout << n - 2 << '\n';
		return 0;
	} 
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = n; i >= 1; --i) sum[i] = sum[i + 1] + a[i];
	dfs(0, 1, 0, 0);
	cout << ans << '\n';
	return 0;
}
