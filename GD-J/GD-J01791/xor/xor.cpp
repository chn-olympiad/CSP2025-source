#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct Node{
	int start, end, cnt = 0;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, mx = 0;
	cin >> n >> k;
	vector<int> a(n, 0);
	for (auto &x : a) cin >> x;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) dp[i][i] = a[i];
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++) 
			dp[i][j] = dp[i][j - 1] ^ a[j];
	queue<Node> q;
	q.push({-1, -1, 0});
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		mx = max(mx, now.cnt);
		for (int i = now.end + 1; i < n; i++) 
			for (int j = i; j < n; j++) 
				if (dp[i][j] == k) q.push({i, j, now.cnt + 1});
	} cout << mx;
} 
