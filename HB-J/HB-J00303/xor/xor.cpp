#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 2e6 + 5;
int n, k, s[N], lst[M];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) s[i] ^= s[i - 1];
	memset(lst, -1, sizeof lst);
	lst[0] = 0;
	int qwq = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (lst[s[i] ^ k] != -1 && lst[s[i] ^ k] >= qwq) {
			qwq = i;
			res++;
		}
		lst[s[i]] = i;
	}
	cout << res << "\n";
	return 0;
}
