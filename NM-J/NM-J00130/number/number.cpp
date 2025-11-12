#include<bits/stdc++.h>
using namespace std;

int n;
int c[15];
char s[1000006];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1); n = strlen(s + 1);
	for(int i = 1; i <= n; i++) if(s[i] >= '0' && s[i] <= '9') c[s[i] - '0']++;
	for(int i = 9; i >= 0; i--) for(int j = 1; j <= c[i]; j++)
		printf("%d", i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
