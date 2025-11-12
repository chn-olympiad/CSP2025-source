#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m;
bool s[N];
int c[N];
long long ans;

void calc(const vector<int> &plan) {
	int went = 0;
	for (int i = 0; i < plan.size(); i++) {
		auto er = plan[i];
		if (went >= c[er] || !s[i]) {
			went++;
		} 
	}
	if (n - went >= m) ans++;
}

bool vis[N];

void dfs(vector<int> now) {
	if (now.size() == n) {
		calc(now);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			now.push_back(i);
			vis[i] = 1;
			dfs(now);
			now.pop_back();
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	string S;
	cin >> S;
	int sum = 0;
	for (int i = 0; i < n; i++) s[i] = S[i] - '0', sum += s[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (sum < m) {
		cout << 0;
		return 0;
	}
	dfs({});
	cout << ans;
}
