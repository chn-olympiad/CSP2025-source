#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans, a[5005];
vector<int> res;
bool used[5005];

void dfs(int dep) {
	if (dep > n) return;
	if (dep > 3) {
		int sum = 0, maxx = -1e9;
		for (int r : res) {
			sum += r;
			maxx = max(maxx, r);
		}
		if (sum > maxx * 2) ans++;
		return;
	}
	for (int i = 1;i <= n;i++) {
		if (!used[i]) {
			used[i] = true;
			res.push_back(a[i]);
			dfs(dep + 1);
			used[i] = false;
			res.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	dfs(1);
	cout << ans / 2 << "\n";
	return 0;
}
