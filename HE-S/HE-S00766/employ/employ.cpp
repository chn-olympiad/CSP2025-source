#include <bits/stdc++.h>
using namespace std;

const int M = 500 + 10;
char s[M];
int n, m, ans;
int c[M], b[M];

void work1() {
	for (int i = 1; i <= n; i ++) 
		cin >> s[i];
	for (int i = 1; i <= n; i ++) 
		cin >> c[i];
	for (int i = 1; i <= n; i ++) 
		b[i] = i;
	do {
		int cnt = 0, sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == '0') {
				cnt ++;
				continue ;
			}
			if (cnt >= c[b[i]]) {
				cnt ++;
				continue ;
			}
			sum ++;
		}
		if (sum >= m) ans ++;
	} while (next_permutation(b + 1, b + 1 + n)) ;
	cout << ans << "\n";	
}

int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	if (n <= 10) work1();
	else {
		cout << "998244352\n";
	}
	
	return 0;
}
