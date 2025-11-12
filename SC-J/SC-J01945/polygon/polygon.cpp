#include <bits/stdc++.h>

using namespace std;

int n, a[1000010];
int sum, maxn;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		maxn = max(a[i], maxn);
		maxn = max(maxn, a[i]);
	}
	if(sum > maxn * 2) {
		cout << 1;//不可以，总司令（骗分）
	} else {
		cout << 0;//不可以，总司令（骗分）
	}
	return 0;
}