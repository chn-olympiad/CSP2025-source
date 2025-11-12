#include <bits/stdc++.h>
#define frein(x) freopen(x, "r", stdin);
#define freot(x) freopen(x, "w", stdout);
using namespace std;
using ll = long long;
string s;
priority_queue <int> q;
int main() {
	frein("number.in");
	freot("number.out");
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			q.emplace(s[i] - '0');
		}
	}
	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
	return 0;
}
