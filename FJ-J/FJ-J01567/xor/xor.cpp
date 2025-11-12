#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n = 0, k = 0;
int a[N] = {};
int s[N] = {};
int ans = 0;
int t[N] = {};
int ok = 0;
int kk = 0;
int f[N] = {};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	s[1] = a[1];
	for (int i = 2; i <= n; i++) {
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			if ((s[i] ^ s[j - 1]) == k) {
				f[i] = max(f[i], f[j - 1] + 1);
			}

		}
		f[i] = max(f[i], f[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
//		cout << f[i] << " ";
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}
