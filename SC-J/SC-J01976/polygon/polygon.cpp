#include <bits/stdc++.h>
using namespace std;
const int maxn = 998244353;
int s[5001];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	cout << int (max(sum / n + s[0] % 2, int(pow(s[2], 2)))) % maxn;
	return 0;
} 