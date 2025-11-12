#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int n, a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0, maxn = -1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
	if (sum > maxn * 2) cout << 1;
	else cout << 0;
	return 0;
}

