#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	int a[125];
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	
	int R = a[1];
	
	sort (a + 1, a + n * m + 1, cmp);
	
	int r = 1, c = 1;
	for (int i = 1; i <= n * m; ++i) {
		if (R == a[i]) {
			cout << c << " " << r;
			return 0;
		}
		
		if (c % 2 == 1) {
			r++;
		} else {
			r--;
		}
		
		if (r % n == 1 && r != 1) {
			c++;
			r--;
		} else if (r == 0) {
			c++;
			r++;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

// 2 2 99 100 97 98
// 2 2 98 99 100 97
// 3 3 94 95 96 97 98 99 100 93 92