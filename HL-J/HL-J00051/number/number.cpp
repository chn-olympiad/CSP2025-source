#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	priority_queue<int> pq;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			pq.push(s[i] - '0');
		}
	}
	while (pq.size()) {
		cout << pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
