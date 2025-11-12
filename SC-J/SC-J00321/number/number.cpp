#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
priority_queue <int> q;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size(); 
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			q.push(x);
		}
	}
	int len = q.size();
	if (q.top() == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= len; i++) {
		cout << q.top();
		q.pop();
	}
	return 0;
} 