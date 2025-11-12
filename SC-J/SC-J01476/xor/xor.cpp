#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

int n, b[N];
long long a[N], m, cnt, k;

void func(int st) {
	if (st + k - 1 > n)return;
	if (k == 1) {
		for (int i = 1; i <= n; ++i) {
			if (a[i] == m) {
				++cnt;
				b[i] = 1;
			}
		}
		return;
	}
	if (b[st] == 1) {
		func(st + 1);
		return;
	}
	int xx = a[st], aa = st + k;
	for (int i = st + 1; i < aa; ++i) {
		if (b[i] == 1) {
			func(st + 1);
			return;
		}
		xx ^= a[i];
	}
	if (xx == m) {
		++cnt;
		for (int i = st; i < aa; ++i) {
			b[i] = 1;
		}
	}
	func(st + 1);
	return;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		k = i;
		func(1);
	}
	cout << cnt;
	return 0;
}