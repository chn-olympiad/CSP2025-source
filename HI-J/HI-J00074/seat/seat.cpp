#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;

int n , m , grade[N];
int R , pos;

int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++) {
		cin >> grade[i];
	}
	R = grade[1];
	sort(grade + 1 , grade + n * m + 1 , greater<int>());
	for(int i = 1 ; i <= n * m ; i++) {
		if(grade[i] == R) {
			pos = i;
			break;
		}
	}
	int x = 0 , y = ceil(1.0 * pos / n);
	if(y % 2 == 1) {
		if(pos % n == 0) {
			x = n;
		} else {
			x = pos % n;
		}
	} else {
		x = n + 1 - pos % n;
	}
	cout << y << " " << x;
	return 0;
}

