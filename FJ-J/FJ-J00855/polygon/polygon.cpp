#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 5010;
const int mod = 998244353;
int a[N];
int f[N][N];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		if (a[3] < a[1] + a[2]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
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