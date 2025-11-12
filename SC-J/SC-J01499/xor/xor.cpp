/*
so? CSP-J 红橙黄黄?
666
来luogu找我：1023865
*/
#include <cstdint>
#include <iostream>

using namespace std;

constexpr int N = 5e5 + 10, M = 1 << 20;
int n, k, a[N], b[M], f[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] ^= a[i - 1];
	for (int i = 0; i < M; i++) b[i] = -1;
	b[0] = f[0] = 0;
	for (int i = 1; i <= n; i++)
		b[a[i]] = max(b[a[i]], f[i] = max(b[a[i] ^ k] + 1, f[i - 1]));
	cout << f[n] << endl;
	return 0;
}
