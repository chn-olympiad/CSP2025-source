#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using stu = array<int, 3>;
using pii = pair<int, int>;

int solve() {
	int n;
	cin >> n;
	vector<stu> v(n);
	
	int ans = 0;
	vector<int> q[3];
	
	for(int i = 0; i < n; i ++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
		vector<int> id{0, 1, 2};
		sort(id.begin(), id.end(), [&v, i](int a, int b) {return v[i][a] > v[i][b];});
		q[id[0]].emplace_back(v[i][id[0]] - v[i][id[1]]);
		ans += v[i][id[0]];
	}
	
	for(int i = 0; i < 3; i ++) {
		sort(q[i].begin(), q[i].end(), greater<int>());
		while(q[i].size() > n / 2) {
			ans -= q[i].back();
			q[i].pop_back();
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("club");
	
	int T;
	cin >> T;
	while(T --) {
		cout << solve() << "\n";
	}
}
