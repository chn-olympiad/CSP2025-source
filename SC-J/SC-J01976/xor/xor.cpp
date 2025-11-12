#include <bits/stdc++.h>
using namespace std;
int s[500001];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	cout << s[0] << endl;
	return 0;
} 