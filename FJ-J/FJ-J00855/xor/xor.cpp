#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 5e5 + 10;
int a[N];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n = read(), k = read();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int l = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			l = i + 1;
			continue;
		}
		if (i == l) {
			continue;
		}
		int sum = a[i];
		for (int j = i - 1; j >= l; j--) {
			sum = (sum xor a[j]);
//			cout << i << " " << j << " " << sum << endl;
			if (sum == k) {
				ans++;
				l = i + 1;
				break;
			} 
		}
	}
	cout << ans;
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') {
			Cf = -1;
		}
	}
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Ca * Cf;
}