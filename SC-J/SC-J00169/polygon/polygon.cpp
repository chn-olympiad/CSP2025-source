#include <bits/stdc++.h>
using namespace std;
int n, a[5003], b, ans, h;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n; ++i) {
		cin >> a[i];
		if(a[i] > b) b = a[i];
		h += a[i];
	}
	if(n == 3) {
		if(h > 2 * b) {
			ans++;
		}
	}else {
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}