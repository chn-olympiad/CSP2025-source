#include <bits/stdc++.h>
using namespace std;
int n, m, s[506], c[506], flag = 0;
char S[506];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", S);
	for (int i = 1;i <= n;i++) {
		s[i] = S[i] - '0';
		if (s[i] == 0)
			flag = 1;
	}
	for (int i = 1;i <= n;i++)
		scanf("%d", &c[i]);
	if (m == 1) {
		// 2 ^ 18 = 262144
		printf("0\n");
	}
}
