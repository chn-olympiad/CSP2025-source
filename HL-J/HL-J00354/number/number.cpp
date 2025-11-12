#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
char a[N];
int b[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int k = 1;
	cin >> a;
	int f = strlen(a) - 1;
	for (int i = 0; i <= f; i++) {
		int tmp = int(a[i]);
		if (tmp >= 48 && tmp <= 57) {
			b[k++] = tmp - 48;
		}
	}
	k--;
	sort(b + 1, b + k + 1, cmp);
	for (int i = 1; i <= k; i++) {
		cout << b[i];
	}
	return 0;
}