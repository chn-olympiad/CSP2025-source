#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 50;
int n, m, a[N];
int Grade, Pos;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	
	Grade = a[1];

	sort(a + 1, a + n * m + 1, greater<int>());
	
	for (int i = 1; i <= n * m; i++) {
		if (Grade == a[i]) {
			Pos = i;
			break;
		}
	}
	
	int k = (Pos - 1) / n + 1;
	if (k % 2 == 1) {
		cout << k << " " << (Pos - 1) % n + 1;
	} else {
		cout << k << " " << n - ((Pos - 1) % n);
	}

	return 0;
}
