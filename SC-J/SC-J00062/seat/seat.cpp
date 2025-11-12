#include <bits/stdc++.h>

using namespace std; 

int n, m, t, x, y;
int A[105];

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++) 
		cin >> A[i];
		
	t = A[1], x = 1, y = 1;
	sort(A + 1, A + n * m + 1, greater<int>());
	
	for (int i = 1; i <= n * m; i++) {
		if (A[i] == t) {
			cout << y << ' ' << x;
			return 0;
		} else {
			if (y % 2 == 1) {
				x++;
				if (x == n + 1) x--, y++;
			} else {
				x--;
				if (x == 0) x++, y++;
			}
		}
	}
	
	return 0;
}