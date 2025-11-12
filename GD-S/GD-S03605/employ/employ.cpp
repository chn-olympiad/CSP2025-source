#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, s[505], char_s, c[505];
bool A = true;
int ans =1;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf(" %c ", &char_s);
		s[i] = char_s - '0';
		if(s[i] == 0) {
			A = false;
		}
	}
	for(int j = 1; j <= n; j ++) {
		scanf(" %d", &c[j]);
	}
	if(A) {
		if(n == m) {
			ans = 1;
			for(int i = 1; i <= n; i ++) {
				ans = (ans * i )% MOD;
			}
			printf("%d", ans);
			return 0;
		}
		for(int M = m; M <= n; M ++) {
			ans *= M;
		}
		printf("%d", &ans);
		return 0;
	}
	printf("0");
	return 0;
}

