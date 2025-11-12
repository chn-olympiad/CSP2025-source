#include<cstdio>
char c;
int num[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (scanf("%c", &c) != EOF) if (c >= '0' && c <= '9') ++num[c - '0'];
	for (int i = 9; i >= 0; --i) while (num[i]--) printf("%d", i);
	fclose(stdin); fclose(stdout);
	return 0;
}
