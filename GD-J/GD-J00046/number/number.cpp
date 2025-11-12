#include <bits/stdc++.h>
using namespace std;
struct num {
	int n, c;
	bool operator < (const num& other) const {
		return n > other.n;
	}
};
map<int, int> m;
vector<num> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c;
	while (cin >> c) {
		if ('0' <= c && c <= '9') m[c - '0']++;
	}
	for (auto it: m) v.push_back({it.first, it.second});
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].c; j++) cout << v[i].n;
	}
	return 0;
}
