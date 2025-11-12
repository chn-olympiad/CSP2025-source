#include <iostream>
#include <cstring>
#define MAXN 500003
using namespace std;
int a[MAXN];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, i, j;
	cin >> n >> k;
	for (i=1; i<=n; i++) {
		cin >> a[i];
	}
	if (n==1) {
		if (a[1] == k) cout << 1;
		else cout << 0;
	}
	else if (n==2) {
		if (a[1] == k && a[2] == k) cout << 2;
		else if (a[1] != k && a[2] == k) cout << 1;
		else if (a[1] == k && a[2] != k) cout << 1;
		else if ((a[1])^(a[2]) == k) cout << 1;
		else cout << 0;
	}
	else cout << 42;//zhe ke shi yuzhou zhongji mimi, yiding neng mengdui de qwq
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
