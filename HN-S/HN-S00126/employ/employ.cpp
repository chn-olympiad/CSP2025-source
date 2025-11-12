#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, c[N];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << m;
	return 0;
}
