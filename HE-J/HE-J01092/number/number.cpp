#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int a[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int l = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++l] = s[i] - '0';
	}	
	sort(a + 1, a + l + 1);
	for (int i = l; i >= 1; i--)
		printf("%d", a[i]);
//	printf("Time : %d", clock());
	return 0;
} 
