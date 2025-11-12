#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;
int a[N], sc, fx, posx, posy;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	
	sc = a[1];
	
	sort(a + 1, a + 1 + n * m);
	
	posx = 1, posy = 1, fx = 1;
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == sc) {
			cout << posx << ' ' << posy;
			break;
		}
		
		if (fx == 1) {
			if (posy == n) {
				posx++, fx = 2;
			} else posy++;
		} else {
			if (posy == 1) {
				posx++, fx = 1;
			} else posy--;
		}
	}
	
	return 0;
}
// AC this!
// And AK CSP!