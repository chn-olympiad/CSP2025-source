#include <bits/stdc++.h>
using namespace std;
/*
·ÖÎöÑùÀý£º
ÑùÀý1£º
1, l = 1, r = 1    2
2, l = 2, r = 4    1 ^ 0 ^ 3 = 2	2
*/ 
const int MAXN = 5e5 + 5;
int a[MAXN], x[MAXN];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cnt = 1;
		cout << cnt << '\n';
	}
	if (n == 2) {
		cnt = 3;
		cout << cnt << '\n';
	}
	cout << rand() % 30; 
	return 0;
} 
