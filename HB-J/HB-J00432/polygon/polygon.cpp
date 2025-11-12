#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[500001];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	cout << (sum > 2 * a[n - 1]);
	return 0;
}
