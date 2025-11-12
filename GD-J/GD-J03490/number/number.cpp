#include <bits/stdc++.h>
using namespace std;

const int N = 1010000;

char s[N], t[N];
int n, m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) if (isdigit(s[i])) {
		t[++m] = s[i];
	}
	sort(t + 1, t + m + 1, greater<int>());
	printf("%s\n", t + 1);
	return 0;
}