/*
T3.replace
? pts
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const int MaxN = 2e5;
const int MaxLen = 5e6;

int n, q;
string s[MaxN + 10][2];
	string t[2];
int l, r;
void kmp (string s, int border[]) {
	border[0] = -1;
	border[1] = 0;
	for (int i = 2; i <= s.size(); ++i) {
		int j = i - 1;
		while (border[j] > -1 && s[border[j] + 1 - 1] != s[i - 1]) {j = border[j];}
		border[i] = border[j] + 1;
	}
}
int border[2][MaxLen + 10];
int ans;

void work_q () {
	cin >> t[0] >> t[1];
	if (t[0].size() != t[1].size()) {
		printf("0\n");
		return;
	}
	l = r = -1;
	for (int i = 1; i <= t[0].size(); ++i) {
		if (t[0][i - 1] != t[1][i - 1]) {
			if (l == -1) {l = i;}
			else {r = i;}
		}
		// printf("%i %c %c\n", i, t[0][i - 1], t[1][i - 1]);
	}
	// printf("%i %i\n", l, r);
	// cout << t[0] << ' ' << t[1] << '\n';
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		kmp(s[i][0] + '#' + t[0], border[0]);
		kmp(s[i][1] + '#' + t[1], border[1]);
		// cout << s[i][0] << ' ' << s[i][1] << '\n';
		// for (int i = 1; i <= t[0].size(); ++i) {printf("%i ", border[0][i]);} printf("\n");
		// for (int i = 1; i <= t[1].size(); ++i) {printf("%i ", border[1][i]);} printf("\n");
		for (int j = 1; j <= t[0].size(); ++j) {if (border[0][s[i][0].size() + 1 + j] == s[i][0].size() && border[1][s[i][1].size() + 1 + j] == s[i][1].size() && j - s[i][0].size() + 1 <= l && r <= j) {
			++ans;
			// printf("%i %i\n", i, j);
		}}
	}
	printf("%i\n", ans);
}
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%i%i", &n, &q);
	for (int i = 1; i <= n; ++i) {cin >> s[i][0] >> s[i][1];}
	while (q--) {work_q();}
	return 0;
}