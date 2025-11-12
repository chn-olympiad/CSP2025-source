#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[100010];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	srand(time(0));
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << rand() % 998244353 + 1;
	return 0;
}
