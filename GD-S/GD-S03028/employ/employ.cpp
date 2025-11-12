#include <bits/stdc++.h>
using namespace std;
struct person{
	int x, y;
}p[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].y;
		p[i].x = s[i] = '0';
	}
	return 0;
}
