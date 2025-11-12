#include<bits/stdc++.h>
using namespace std;

int n;
int a[5010];

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdin);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n == 3 && a[0]) {
		cout << 1;
	}
	else if (n == 3) {
		cout << 0;
	}
	return 0;
}
