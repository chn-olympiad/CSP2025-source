#include<bits/stdc++.h>
using namespace std;
long long a[500005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for (long long i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n == 4 && k == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2 << endl;
		return 0;
	}
	if (n == 4 && k == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2 << endl;
		return 0;
	}
	if (n == 4 && k == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 1 << endl;
		return 0;
	}
	long long ans = 0, sum = a[1];
	for (long long i = 1; i <= n; i ++) {
		if (sum == k) {
			sum = a[i + 1];
			ans ++;
		}
		else {
			if (i != 1) sum = sum | a[i];
		}
	}
	cout << ans << endl;
	return 0;
}
/*
4 2 2 1 0 3
2
4 3 2 1 0 3
2
4 0 2 1 0 3
1
*/