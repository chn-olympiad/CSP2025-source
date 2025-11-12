//----------------------------------------------RP += INF!--------------------------------------
// Wu Yue Depth-First Search GIVE ME THE POWER
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

//4 2 2 1 0 3
int dfs(const vector<vector<int>> &adj, int depth, int u, vector<bool> vis) {
	if (adj[u].size() == 0 || vis[u]) return depth;
	for (const int &v : adj[u]) {
		vis[v] = true;
		return dfs(adj, depth + 1, v, vis);
	}
	return depth;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), bits, prefix(n + 1, 0);
	int tk = k;
	while (tk > 0) {
		bits.push_back(tk & 1);
		tk >>= 1;
	}
	reverse(bits.begin(), bits.end());
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i != 1) {
			prefix[i] = prefix[i - 1] ^ a[i];
		} else {
			prefix[i] = a[i];
		}
	}
	// 1 2 3 4 5
	// 
	if (n <= 1e3) {
		vector<pair<int, int>> v;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				int curr = prefix[i] ^ prefix[j - 1];
				if (curr == k) v.push_back({j, i});
			}
		}
		vector<vector<int>> adj((int)v.size() + 1);
		for (int i = 0; i < (int)v.size(); ++i) {
			for (int j = 0; j < (int)v.size(); ++j) {
				if (v[i].first > v[j].second) {
					adj[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < (int)v.size(); ++i) {
			cout << endl;
			vector<bool> vis((int)v.size() + 1, false);
			ans = max(ans, dfs(adj, 1, i, vis));
		}
		cout << ans << endl;
		return;
	}
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
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
