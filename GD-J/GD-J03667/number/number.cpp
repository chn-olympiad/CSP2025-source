#include <iostream>
#include <queue>
using namespace std;

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	
	string s;
	priority_queue<int> q;
	cin >> s;
	for (char c: s) {
		if ('0' <= c && c <= '9') {
			q.push(c-'0');
		}
	}
	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
	
	return 0;
} 
