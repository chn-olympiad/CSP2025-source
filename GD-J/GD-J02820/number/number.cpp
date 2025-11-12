#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 1e6 + 10;
int tot, a[N];
string s;
bool cmp (int x, int y) {
	 return x > y;
}
void write (int x) {
	 if (x < 0) putchar ('-'), x = -x;
	 if (x > 9) write (x / 10);
	 putchar (x % 10 + '0');
}
signed main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    cin >> s;
	for (char i : s) {
		if (i >= '0' && i <= '9')
		   a[++tot] = (i - '0');
	}	
	stable_sort (a + 1, a + 1 + tot, cmp);
	for (int i = 1; i <= tot; i++)
	    write (a[i]);
	return 0;
} 
