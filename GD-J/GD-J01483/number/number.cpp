#include <bits/stdc++.h>
using namespace std;
// number
const int N = 1e6 + 5;
char s[N];
int cnt[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i ++ )
		if (s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - '0'] ++ ;
	for (int i = 9; i >= 0; i -- )
		while (cnt[i]) {
			putchar('0' + i);
			cnt[i] -- ;
		}
	return 0;
}

// rp ++ ;
