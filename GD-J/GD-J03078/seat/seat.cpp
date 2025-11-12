#include <iostream>
#include <algorithm>
using namespace std;
int a[200];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, i, r, pos=1, x, y;
	cin >> n >> m;
	for (i=1; i <= n*m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a+1, a+n*m+1, cmp);
	for (i=1; i<=n*m; i++) {
		if (a[i] == r) pos = i;
	}
	
	if (pos % n == 0) x = pos / n;
	else x = pos / n + 1;
	
	if (x % 2 == 1) {
		if (pos % n == 0) y = n;
		else y = pos % n;
	}
	else {
		if (pos % n == 0) y = 1;
		else y = n + 1 - pos % n;
	}
	cout << x <<' '<< y;
	return 0;
}

//ccf i love you
/*
  CCCC   CCCC  FFFF    I   L     OOO   V     V EEEE    U   U
 C      C      F       I   L    O   O   V   V  E       U   U
 C      C      FFFF    I   L    O   O    V V   EEEE    U   U
 C      C      F       I   l    O   O    V V   E       U   U
  CCCC   CCCC  F       I   LLLL  OOO      V    EEEE     UUU
*/
//wo yao shang csp mihuo xingwei daquan qwq
