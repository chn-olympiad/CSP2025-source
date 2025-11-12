#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
int c[510];
int p[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) p[i] = 1;
	int cnt = 0;
	do {
		int i = 1, l = 0, c1 = 0;
		while (i <= n) {
			if (l >= c[p[i]]) i++, l++;
			if (s[i - 1] == '0') i++, l++;
			l = 0;
			i++, c1++;
		}
		if (c1 >= m) cnt++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << cnt << endl;
}
