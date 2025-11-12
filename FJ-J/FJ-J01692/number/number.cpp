#include <bits/stdc++.h>

using namespace std;

const int L = 1E6;
char s[L + 1];
int a[10];

int main() {
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 1; i <= l; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++)
			printf("%d", i);
	printf("\n");
	return 0;
}





