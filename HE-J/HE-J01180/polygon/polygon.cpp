#include <bits/stdc++.h>
using namespace std;
int n, a[3];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	cin >> a[1] >> a[2] >> a[3];
	sort(a, a + 3);
	if (a[1] + a[2] > a[3])
		cout << 1;
	else
		cout << 0;
}
