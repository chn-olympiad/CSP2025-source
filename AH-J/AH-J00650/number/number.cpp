#include<iostream>
#include<string>
#include<queue>
using namespace std;
priority_queue<char> q;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		if (s[i]>='0'&&s[i]<='9') q.push(s[i]);
	}
	while(!q.empty()) {
		cout << q.top();
		q.pop();
	}
	return 0;
}
