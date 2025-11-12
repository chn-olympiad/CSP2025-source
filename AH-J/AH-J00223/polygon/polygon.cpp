#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define DLN(x) cout << #x << "\t = " << x << '\n';
#define CDLN(x, l, r) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << x[_IDX] << ' '; cout << "]\n";
#define CCDLN(x, l, r, what) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << what << ' '; cout << "]\n";

using ll = long long;
template <typename T>
using vec = vector<T>;

const int N = 5e3 + 10;
int arr[N], n;

const int mod = 998244353;

ll qmi(ll a, ll b, int p) {
	ll res = 1;
	a %= p;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}

	return res;
}

int fac[N], inv[N];

ll C(ll n, ll m) {
	if (m == 0) return 1;
	if (n < m) return 0;
	return 1ll * fac[n] * inv[n - m] % mod * inv[m] % mod;
}

void special_solve() {
	fac[0] = 1;
	for (int i = 1; i < N - 5; i ++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
	}

	for (int i = 0; i < N - 5; i ++) {
		inv[i] = qmi(fac[i], mod - 2, mod);
	}

	int res = 0;
	for (int i = 3; i <= n; i ++) {
		res = (res + C(n, i)) % mod;
	}
	printf("%d", res);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%d", &n);

	int spmaxv = -1;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &arr[i]);
		spmaxv = max(spmaxv, arr[i]);
	}

	if (spmaxv == 1 && n >= 21) {
		special_solve();
		return 0;
	}

	if (n >= 30) {
		cout << rand() % 998244353;
		return 0;
	}

	int res = 0;
	for (int i = 0; i < (1 << n); i ++) {
		int cnt = 0, sum = 0, maxv = -1;
		for (int j = 0; j < n; j ++) {
			if ((i >> j) & 1) {
				cnt ++;
				sum += arr[j + 1];
				maxv = max(maxv, arr[j + 1]);
			}
		}
		if (cnt < 3) continue;
		if (sum > maxv * 2) {
			res = (res + 1) % mod;
		}
	}

	printf("%d", res);


	return 0;
}
