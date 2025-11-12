#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
int a[N][4], cnt[4];
int ans = 0;
set <int> s[4];
void dfs(int k, int sum) {
	if(k == n + 1) {
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= 3; i++) {
		if(cnt[i] >= n / 2) {
			continue;
		}
		cnt[i]++;
		dfs(k + 1, sum + a[k][i]);
		cnt[i]--;
	}
}
struct node{
	int id, from, to, val;
	friend bool operator < (const node in1, const node in2) {
		return in1.val < in2.val;
	}
};
priority_queue <node> q;
void solve() {
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	while(q.size()) q.pop();
	s[1].clear();
	s[2].clear();
	s[3].clear();
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	if(n <= 10) {
		dfs(1, 0);
		cout << ans << "\n";
		return;
	}
	for(int i = 1; i <= n; i++) {
		pair <int, int> mx = {0, 0};
		for(int j = 1; j <= 3; j++) {
			mx = max(mx, {a[i][j], j});
		}
		s[mx.second].insert(i);
		ans += a[i][mx.second];
		for(int j = 1; j <= 3; j++) {
			if(j != mx.second) {
				q.push({i, mx.second, j, a[i][j] - a[i][mx.second]});
			}
		}
	} 
	while((s[1].size() > n / 2 || s[2].size() > n / 2 || s[3].size() > n / 2) && q.size()){
		node w = q.top();
		q.pop();
		if(s[w.from].size() >= n / 2 && s[w.to].size() < n / 2 && (s[w.from].find(w.id) != s[w.from].end())) {
			s[w.from].erase(w.id);
			s[w.from].insert(w.id);
			ans += w.val;
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
} 
