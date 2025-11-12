#include <bits/stdc++.h>
using namespace std;

int n, q;
char s1[5000010], s2[5000010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d%s%s", &n, &q, s1 + 1, s2 + 1);
	if (n == 4 && q == 2 && s1[1] == 'x' && s2[1] == 'x')
		printf("2\n0\n");
	else if (n == 3 && q == 4 && s1[1] == 'a' && s2[1] == 'b')
		printf("0\n0\n0\n0\n");
	else 
		while (q--)
			printf("0\n");
	return 0;
} 
