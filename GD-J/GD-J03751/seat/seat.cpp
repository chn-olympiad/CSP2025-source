#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[105];

    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    
    int g = a[0];
    sort(a, a + n * m);

    for (int i = n * m - 1; i >= 0; i--) {
    	if (a[i] == g) {
    		g = n * m - i;
    		break;
		}
	}

    int x, y;
    x = g / n + 1;
    if (g % n == 0) x--;
	if (x % 2 != 0) {
		y = g % n;
		if (y == 0) y = n;
	} else {
		y = n - g % n + 1;
		if (g % n == 0) y = 1;
	}
	
	cout << x << ' ' << y << '\n';
    
    fclose(stdin);
    fclose(stdout);
	return 0;
}
