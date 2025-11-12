#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	priority_queue <int> q;
	for (char c : s) {
		if (c >= '0' && c <= '9') q.push(c - '0');
	}
	while (!q.empty()) cout << q.top(), q.pop();
	return 0;
}
