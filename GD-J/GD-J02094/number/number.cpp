#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	priority_queue <int> q;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			q.push(s[i] - '0');
		}
	}
	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
	return 0;
}
