#include <bits/stdc++.h>
using namespace std;
int n, s[5010];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	if(n < 3) {
		cout << 0;
		return 0;
	}
	if(n == 3) {
		sort(s + 1, s + 1 + n);
		if(s[3] > s[1] + s[2]) cout << 0;
		else cout << 1;
		return 0;
	}
	return 0;
}

