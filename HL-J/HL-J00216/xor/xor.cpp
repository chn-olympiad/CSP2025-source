#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5;
constexpr int D = 20;

int n, k, a[N + 1];
int s[N + 1], lst[1 << D], l[N + 1];
int f[N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(lst, -1, sizeof lst);
	lst[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
		if (lst[s[i] ^ k] != -1)
			l[i] = lst[s[i] ^ k] + 1;
		lst[s[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (l[i])
			f[i] = max(f[i], f[l[i] - 1] + 1);
	}
	cout << f[n] << '\n';
	return 0;
}