#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 15;

char s[N];
int t[10];

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	scanf ("%s", s + 1);
	int n = strlen (s + 1);
	for (int i = 1; i <= n; ++ i) {
		if (s[i] >= '0' && s[i] <= '9') t[s[i] - '0'] ++;
	}
	for (int i = 9; i >= 0; -- i) {
		while (t[i] --) {
			printf ("%d", i);
		}
	}
	puts ("");
	return 0; 
}