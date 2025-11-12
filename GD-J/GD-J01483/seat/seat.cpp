#include <bits/stdc++.h>
using namespace std;
// seat
int n, m;
const int N = 105;
int a[N];
int R;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; int num = n * m;
	for (int i = 1; i <= n; i ++ ) 
		for (int j = 1; j <= m; j ++ )
			cin >> a[(i - 1) * m + j];
	R = a[1];
	sort(a + 1, a + num + 1, greater<int>());
	int pos = 0;
	for (int i = 1; i <= num; i ++ ) 
		if (R == a[i]) {
			pos = i;
			break;
		}
	int c = (pos - 1) / n + 1, tp = (pos - 1) % n + 1, r = 0;
	if (c & 1) r = tp;
	else r = n - tp + 1;
	cout << c << " " << r << '\n'; 
	return 0;
}
