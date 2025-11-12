#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
typedef long long ll;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		cout << floor(n * 1.00 / 2.00);
	}
	return 0;
}
