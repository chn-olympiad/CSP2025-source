#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
char str[N];
int t[11] = {};

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", str + 1);
	int l = strlen(str + 1);
	for (int i = 1; i <= l; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			t[str[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= t[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
