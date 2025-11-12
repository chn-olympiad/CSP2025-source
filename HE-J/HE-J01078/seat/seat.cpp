#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200];

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int k = n * m;
	for (int i = 1; i <= k; i ++) cin >> a[i];
	int t = a[1];
	sort(a + 1, a + 1 + k, greater < int > ());
	int pos = 0;
	for (int i = 1; i <= k; i ++) {
		if (a[i] == t) {
			pos = i;
			break ;
		}
	}
	int r = ceil(1.0 * pos / n);
	cout << r << " ";
	int tot = (r - 1) * n;
	if (r % 2 == 1) {
		cout << pos - tot << "\n";
	} else {
		cout << n - pos + tot + 1 << "\n";
	}
	
	return 0;
}
