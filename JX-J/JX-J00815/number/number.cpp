#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < int(s.size()); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            q.push(s[i] - '0');
        }
	}
	int ans = 0;
	while(!q.empty()) {
        cout << q.top();
        q.pop();
	}
	cout << '\n';
}
