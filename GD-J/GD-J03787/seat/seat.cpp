#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], r, nx, ny, flag;
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++) 
    	cin >> a[i];
    r = a[1];
    sort (a + 1, a + n * m + 1, greater <int> ());
    if (a[1] == r) {
    	cout << "1 1";
    	return 0;
	}
	int x = 1, y = 1;
	nx = x, ny = y;
    for (int i = 2; i <= n * m; i ++) {
    	if (! flag) ny ++;
		else ny --;	
    	if (ny > m) nx ++, ny = m, flag = 1;
    	else if (ny < 1) nx ++, ny = 1, flag = 0;
    	if (a[i] == r) {
    		cout << nx << ' ' << ny;
    		return 0;
		}
	}
    return 0;
}

