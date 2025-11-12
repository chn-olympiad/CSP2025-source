#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > q;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s;
	 for (int i = 0; i < s.size(); ++i) {
	 	if ('0' <= s[i] && s[i] <= '9') {
	 		q.push(s[i] - '0');
		 }
	 }
	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
}
