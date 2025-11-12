#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> pq;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (char c: s) {
		if ('0' <= c && c <= '9') {
			pq.push(c - '0');
		}
	}
	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	cout << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
