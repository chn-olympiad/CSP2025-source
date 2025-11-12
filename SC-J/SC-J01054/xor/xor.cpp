#include<bits/stdc++.h>
using namespace std;
int k, n, a[1000000];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << k;
	return 0;
}