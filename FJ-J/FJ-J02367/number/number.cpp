#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
char s[N];
int tmp[20];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = strlen(s);
	for (int i = 0; i < len; i++) 
		if (s[i] >= '0' && s[i] <= '9') 
			tmp[s[i] - '0']++;
	for (int i = 9; i >= 0; i--) 
		for (int j = 1; j <= tmp[i]; j++)
			printf("%d", i);
	return 0;
}
