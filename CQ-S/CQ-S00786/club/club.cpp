#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(const vector<vector<int>>& a, const int& sx, const int& m, long long& ans, vector<int> cnt = vector<int>(3, 0), int i = 0, long long sum = 0) {
	if (i >= sx) { return ans = max(ans, sum), void(); }
	for (int j = 0; j < 3; j++) {
		if (cnt[j] >= m)
			continue;
		cnt[j]++;
		dfs(a, sx, m, ans, cnt, i + 1, sum + a[i][j]);
		cnt[j]--;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int m = n / 2;
		vector<vector<int>> a(n, vector<int>(3));
		for (int i = 0; i < n; i++)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		sort(a.begin(), a.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
			if (max(a[0], max(a[1], a[2])) != max(b[0], max(b[1], b[2])))
				return max(a[0], max(a[1], a[2])) > max(b[0], max(b[1], b[2]));
			else
				return (a[0] + a[1] + a[2]) / 3 > (b[0] + b[1] + b[2]) / 3;
		});
		long long ans = 0;
		dfs(a, n, m, ans);
		cout << ans << endl;
	}
	return 0;
}

