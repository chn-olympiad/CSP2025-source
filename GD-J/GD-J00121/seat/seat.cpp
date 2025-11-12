#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int a[128], n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	cin >> a[1];
	int cnt = 0;
	for (int i = 2; i <= n * m; ++i) {
		cin >> a[i];
		if (a[i] > a[1]) ++cnt;
	} 		
	++cnt;
	int l = (cnt - 1) / n + 1; 
	int h = cnt - (l - 1) * n;
	if (l & 1) {
		cout << l << " " << h << "\n";
	} else {
		cout << l << " " << n - h + 1 << "\n";
	}
	return 0;
}

