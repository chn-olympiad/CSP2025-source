#include<bits/stdc++.h>
using namespace std;

char s[1000010];
int a[1000010];

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int t = 0, l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			t++;
			a[t] = s[i] - '0';
		}
	}	
	sort(a + 1, a + t + 1);
	for (int i = t; i >= 1; i--) {
		printf("%d", a[i]);
	}
	return 0;
}
