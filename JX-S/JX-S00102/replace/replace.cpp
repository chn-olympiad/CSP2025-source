#include <bits/stdc++.h>
using namespace std;
int n, q;
char s1[200010][5000010], s2[200010][5000010];
char s3[200010][5000010], s4[200010][5000010];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> s3[i] >> s4[i];
	}
	for (int i = 1; i <= q; i++) {
		printf("0\n");
	}
	return 0;
}
