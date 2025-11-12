#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 511;

int n, m;
int p[20], c[N];
string days;

void sub1to2() {
	for (int i = 1; i <= n; i++) p[i] = i;

	int cnt = 0;
	do {
		int rejected = 0, passed = 0;
		for (int i = 1; i <= n; i++) {
			if (days[i] == '0') {
				rejected++;
			} else {
				if (rejected >= c[p[i]]) {
					rejected++;
				}
				else {
					passed++;
				}
			}
		}
		if (passed >= m) cnt++;
	} while (next_permutation(p + 1, p + 1 + n));
	cout << cnt << '\n';
}

void subA() {

}

void sub12to14() {

}

void sub15() {
	bool has0 = false;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			has0 = true;
			break;
		}
	}

	if (has0) {
		cout << 0 << '\n';
		return;
	}

	sort(c + 1, c + 1 + n);

	if (c[1] == 0) {
		cout << 0 << '\n';
		return;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> days;
	days = ' ' + days;
	for (int i = 1; i <= n; i++) cin >> c[i];

	if (n <= 10) {
		sub1to2();
		return 0;
	}
}

/*
17:38 8pts
100 + 16 + 10 + 8 = 134 pts...
*/