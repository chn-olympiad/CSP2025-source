#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n, k, z;
int a[500030];
int yh(int l, int r) {
	int p = 0;
	for (int i = l; i <= r; i++) {
		p = p^a[i];
	}
	return p;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (yh(i, j) == k) {
				cout << i << ' ' << j << endl;
				cnt++;
				i = j + 1;
				break;
			}

		}
	}
	cout << cnt;
	return 0;
}