#include <iostream>
#include <cstring>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int i,j,len;
	string a;
	cin >> a;
	len = a.length();
	for (i=9; i>=0; i--) {
		for (j=0; j<len; j++) {
			if (a[j] == i + '0') cout << i;
		}
	}
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
