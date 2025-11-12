#include <bits/stdc++.h>
using namespace std;

int n, m, a[114], sum, d = 1;

int main() {
    freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
        if (a[i] > a[1]) {
            sum++;
        }
    }
    int shang = sum / n, yu = sum % n;
    if (shang % 2 == 0) {
        cout << shang + 1 << " " << yu + 1;
    } else {
        cout << shang + 1 << " " << m - yu;
    }
	return 0;
}
