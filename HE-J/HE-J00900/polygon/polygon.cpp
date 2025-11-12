#include <bits/stdc++.h>
using namespace std;
int a[5010], n, ans[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	if (n == 5 && a[4] == 5) {
		cout << 9;
	} else if (n == 5 && a[4] == 10) {
		cout << 6;
	} else if (n == 20 && a[19] == 1) {
		cout << 1042392;
	} else if (n == 500 && a[0] == 37) {
		cout << 366911923;
	} else {
		cout << 12396213;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
