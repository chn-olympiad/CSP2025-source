//----------------------------------------------RP += INF!--------------------------------------
// Wu Yue Depth-First Search SqrtOne YisrT3 GIVE ME THE POWER
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int Mod = 998244353;
int cnt = 0;
int n;
//5 1 2 3 4 5
map<vector<int>, int> mp;
void dfs(const vector<int> &a, vector<bool> vis, int x, vector<int> &progress, int len) {
	if (len >= 3) {
		int maxn = -1, sum = 0;
		for (int i = 0; i < (int)progress.size(); ++i) {
			sum += progress[i];
			maxn = max(maxn, progress[i]);
		}
		if (sum > 2 * maxn) {
			mp[progress] = true;
		}
	}
	for (int i = x + 1; i <= n; ++i) {
		vis[i] = true;
		progress.push_back(i);
		dfs(a, vis, i, progress, len + 1);
		progress.pop_back();
		vis[i] = false;
	}
}
int Combine() {
	int res = 1;
	for (int i = 1; i <= n - 2; ++i) {
		res = res % Mod * 2 % Mod;
	}
	return (res + 1) % Mod;
}
void solve() {
	cin >> n;
	vector<int> a(n + 1);
	bool flag = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i > 1 && a[i] != a[i - 1]) flag = false;
	}
	if (flag) {
		if (n == 3) {
			cout << 1 << endl;
			return;
		}
		else {
			cout << Combine() % Mod<< endl;
			return;
		}
	}
	if (n <= 20) {
		vector<bool> vis(n + 1, false);
		vector<int> progress;
		dfs(a, vis, 0, progress, 0);
		cout << mp.size() << endl;
		return;
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
