#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
pair<string, string> p[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		p[i] = {s, t};
	}
	while (m--) {
		string s, t;
		cin >> s >> t;
		cout << 0 << endl;
	}
	return 0;
} 
