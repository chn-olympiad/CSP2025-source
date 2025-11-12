#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int a[N];
int cnt[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (isdigit(s[i])) {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
}