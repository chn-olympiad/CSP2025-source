#include<bits/stdc++.h>
using namespace std;

int l, n, a[1000010];
char s[1000010];

bool cmp(const int &A, const int &B) {
	return A > B;
}

int main() {
	freopen("number1.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	l = strlen(s + 1);
	for (int i = 1; i <= l; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++n] = s[i] - '0';
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);
	return 0;
}
