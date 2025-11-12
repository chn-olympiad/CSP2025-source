#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}

const int N = 5e5 + 9;
int n, k, a[N], cnt, ans, s[N]; 

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), s[i] = s[i - 1] ^ a[i];
	for (int l = 1, r = 1, mx = 0; r <= n; r++) {
		int t = l;
		mx = max(mx, a[r]);
		if (mx * 2 > k) {
			while (t <= r) {
				if ((s[r] ^ s[t - 1]) == k) {
					ans++;
					l = r + 1, mx = 0;
					break;
				}
				t++;
			}
		}
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}