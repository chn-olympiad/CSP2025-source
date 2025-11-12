#include <bits/stdc++.h>
using namespace std; 
const int N = 15; 
int n, m, R, c, r, k; 
int main() {
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr); 
    freopen("seat.in", "r", stdin); 
    freopen("seat.out", "w", stdout); 
    cin >> n >> m;
    cin >> R; 
    k++; 
    for (int i = 2; i <= n * m; i++) {
		int x; 
		cin >> x; 
		if (x > R)
			k++; 
	}
	c = (k - 1) / n + 1; 
    r = (k - 1) % n + 1; 
    if (c % 2 == 0)
		r = n + 1 - r; 
	cout << c << " " << r << endl; 
    return 0; 
}
