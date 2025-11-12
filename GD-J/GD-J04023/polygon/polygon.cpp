#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i) 
using namespace std;

const int N = 5 * 1e3 + 5;

int n, a[N], ans;
bool vis[N];
void dfs(int l, int c, int sum) {
	if(l > c) {
		//inc(i, 1, n) cout << vis[i] << ' ';
		//cout << '\n';
		int maxnum = 0;
		inc(i, 1, n) {
			if(vis[i]) maxnum = max(maxnum, a[i]);
		}
		if(sum > 2 * maxnum) {
			//cout << sum << "  ";
			//inc(i, 1, n) cout << vis[i] << ' ';
			ans++;
			//cout << '\n';
		}
		return;
	}
	vis[l] = 1;
	dfs(l + 1, c, sum += a[l]);
	vis[l] = 0;
	dfs(l + 1, c, sum -= a[l]);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	inc(i, 1, n) cin >> a[i];
	dfs(1, n, 0);
	cout << ans << '\n';
	return 0; 
}
