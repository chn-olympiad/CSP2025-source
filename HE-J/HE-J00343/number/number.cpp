#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> heap;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			heap.push(s[i] - '0');
		}
	}
	while(!heap.empty()) {
		cout << heap.top();
		heap.pop();
	}
	return 0;
}
