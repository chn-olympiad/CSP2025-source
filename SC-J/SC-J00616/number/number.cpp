#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c;
	while ((c = getchar()) != EOF) {
		if (isdigit(c))a[c - '0']++;
		if (!isprint(c))break;
	}
	for (int i = 9; i >= 0; i--)
		while (a[i]--) putchar(i + '0');
}