#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n;
int a[N];
int ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	if (n == 3) {
		int mx = max(a[1], max(a[2], a[3]));
		int sum = a[1] + a[2] + a[3];
		if (sum > mx * 2) cout << 1 << endl;
		else cout << 0 << endl;
		//cout << sum << ' ' << mx;
		return 0;
	}//else {
	//	sort(a + 1, a + n + 1);
	//	for (int i = n; i >= 1; i -- ) {
	//		
	//	}
	//}
	return 0;
}
