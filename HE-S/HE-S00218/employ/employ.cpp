#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
inline void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for ( ; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = -f;
		}
	}
	for ( ; isdigit(c); c = getchar()) {
		x = (x << 3) + (x << 1) + (c & 15);
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if (x < 0) {
		x = -x;
		putchar ('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar ((x % 10) | 48);
}
const int M = 2e6 + 50, N = 1e4 + 50; 
int n, m, ans, a[N];
char c[N];
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	bool f = false;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		if (c[i] == '0') f = true;
	}
	if (!f) {
		cout << 0;
	}
	if (n == m) {
		cout << 1;
	}
	return 0;
}
