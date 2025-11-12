#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[510];
char s[510];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') cnt++;
	}
	if (cnt == n) {
		int k = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) k++;
		}
		printf("%d", n - k);
	}else if (cnt == 18) {
		
	}
	return 0;
}
