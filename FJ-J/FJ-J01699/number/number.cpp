#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
priority_queue<int> q;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> s;
	for(auto ch : s) {
		if (ch - '0' <= 9 && '9' - ch >= 0) q.push(ch - '0');
	}
	while (!q.empty()) cout << q.top(),q.pop();
	cout << endl;
	return 0;
}
