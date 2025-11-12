#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int ans[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf ("%s", s + 1);
	for (int i = 1; i <= strlen(s + 1); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ans[s[i] - '0']++;
		} 
	}
	for (int i = 9; i >= 0; i--) {
		if (ans[i] > 0) {
			for (int j = 1; j <= ans[i]; j++) {
				printf ("%d", i);
			}
		} 
	} 
	return 0;
}
