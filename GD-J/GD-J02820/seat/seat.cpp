#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e3 + 10;
int n, m, a[N], f[N][N];
int x = 1, y = 1, tot = 1;
bool ff = 1;
inline int read () {
	int val = 0, f = 1;
	char ch = getchar ();
	for (; ch < '0' || ch > '9'; ch = getchar ())
	    if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar ())
	    val = (val << 1) + (val << 3) + (ch ^ 48);
	return val * f; 
}
bool cmp (int x, int y) {
	 return x > y;
}
signed main () {
	
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out","w", stdout);
    cin >> n >> m;
    
    while (x <= n) {
    	f[x][y] = tot;
    	tot++;
    	if (ff) {
    	  if (y == m) x++, ff = 0; 
		  else y++; 
		}
		else {
		  if (y == 1) x++, ff = 1; 
		  else y--;	
		}
	}
    for (int i = 1; i <= n * m; i++)
        a[i] = read();
    int k = a[1], p = 0;
    sort (a + 1, a + 1 + n * m, cmp);
    for (int i = 1; i <= n * m; i++) {
    	if (a[i] == k) {
    	   p = i;
    	   break;
		}
	}
	for (int i = 1; i <= n; i++)
	  for (int j = 1; j <= m; j++)
	      if (f[i][j] == p) {
	      	 cout << i << ' ' << j;
	      	 break;
		  }
	return 0;
} 





