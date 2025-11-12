#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int a[maxn];

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;

	int lens = s.size();

	int cnt = 1;
	for (int i = 0; i < lens; i++) {
		int x = s[i] - '0';
		if (x >= 0 && x <= 9) {
			a[cnt++] = x;
		}
	}

	sort(a + 1, a + cnt);

	for (int i = cnt - 1; i >= 1; i--) printf("%d", a[i]);

	return 0;
}