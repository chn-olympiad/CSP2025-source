#include <bits/stdc++.h>
using namespace std;
unsigned long long  n, k, a[500005], b[500005], l, x,ans;
void read(unsigned long long &a) {
	unsigned long long x = 0;
	char ch;
	ch = getchar();
	while (ch > '9' && ch < '0') {
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') {
		x *= 10;
		x += ch - '0';
		ch = getchar();
	}
	a = x;
	return;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);
	read(k);
	for (long long i = 1; i <= n; i++) {
		read(a[i]);
	}
	l = 1;
	for (int i = 1; i <= n; i++) {
		x = a[l];
		if (x == k) {
			b[l] = max(b[l], 1 + b[l - 1]);
		} else
			for (long long i = l - 1; i >= 1; i--) {
				x = x^a[i];
				if (x == k) {
					b[l] = max(b[l], 1 + b[i - 1]);
					break;
				}

			}
		b[l] = max(b[l], b[l - 1]);
		l++;
	}
	cout << b[n];
	return 0;
}