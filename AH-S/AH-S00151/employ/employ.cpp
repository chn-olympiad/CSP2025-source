#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define DLN(x) cout << #x << "\t = " << x << '\n';
#define CDLN(x, l, r) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << (x[_IDX]) << ' '; cout << "]\n";
#define CCDLN(x, l, r, what) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << (what) << ' '; cout << "]\n";

template <typename T>
using vec = vector<T>;

using ll = long long;

const int N = 510;
const int mod = 998244353;

int c[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	if (n > 18) {
		int res = 1;
		for (int i = 1; i <= n; i ++) {
			res = 1ll * res * i % mod;
		}
		cout << res;
		return 0;
	}

	string str;
	cin >> str;
	vec<int> arr(n);
	for (int i = 1; i <= n; i ++) {
		arr[i - 1] = i;
	}

	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}

	int res = 0;
	do {
		int cnt = 0, a = 0;
		for (int i = 0; i < n; i ++) {
			if (c[arr[i]] <= a) {
				a++;
				continue;
			}
			if (str[i] - '0') cnt ++;
			else a ++;
		}
		res += (cnt >= m);
	} while (next_permutation(arr.begin(), arr.end()));

	cout << res;

	return 0;
}