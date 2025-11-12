#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;

char s[N];
int a[N];
int n, cnt = 0;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = s[i] - '0';
		}
	}
	
	sort(a + 1, a + n + 1, cmp); 
	
	for (int i = 1; i <= cnt; ++i) {
		printf("%d", a[i]);
	}

	return 0;
}
