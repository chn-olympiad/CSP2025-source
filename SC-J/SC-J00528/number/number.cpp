#include <bits/stdc++.h>
using namespace std;
string s, ans;
bool flag = false;
priority_queue<char> pq;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if('0' <= s[i] && s[i] <= '9') {
			if(s[i] != '0') flag = true;
			pq.push(s[i]);
		}
	}
	if(!flag) {
		cout << 0;
		return 0;
	}
	while(!pq.empty()) {
		char t = pq.top();
		pq.pop();
		ans += t;
	}
	cout << ans;
	return 0;
}