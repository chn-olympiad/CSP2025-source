#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int c[N];
int f[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	bool flag = false;
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
		cin >> c[i];
		f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] * i;
	for (int i = 0; i < n; i++)
		if (s[i] != 0) flag = true;
	if (flag) {
		if (m > 18) {
			cout << 0 << endl;
			return 0;
		} else {
			cout << f[m] << endl;
			return 0;
		}
	} else {
		cout << f[m] << endl;
		return 0;
	} return 0;
}
