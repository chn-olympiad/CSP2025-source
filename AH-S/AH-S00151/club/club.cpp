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

const int N = 200 + 10;

int w[N][5];
int f[N][N][N];
int n;

void solve() {
	memset(w, 0, sizeof w);
	memset(f, 0, sizeof f);
	cin >> n;

	for (int i = 1; i <= n; i ++) {
		cin >> w[i][1];
		cin >> w[i][2];
		cin >> w[i][3];
	}

	if (n > 10000) {
		vec<int> a;
		for (int i = 1; i <= n; i ++) {
			a.push_back(w[i][1]);
		}
		sort(a.begin(), a.end(), [](int a, int b) {
			return a > b;
		});
		int res = 0;
		for (int i = 0; i < n / 2; i ++) {
			res += a[i];
		}
		cout << res;
		return;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= i; j ++) {
			for (int k = 0; k <= i; k ++) {
				if (j + k > i) break;
				if (i - j - k > n / 2 ||
					j > n / 2 ||
					k > n / 2) continue;
				f[i][j][k] = max({
					j != 0 ? f[i - 1][j - 1][k] + w[i][1] : -1,
					k != 0 ? f[i - 1][j][k - 1] + w[i][2] : -1,
					i - j - k != 0 ? f[i - 1][j][k] + w[i][3] : -1
				});
				// DLN(f[i - 1][j][k] + w[i][3])
				// DLN((k != 0 ? f[i - 1][j][k - 1] + w[i][2] : -1))
				// DLN((j != 0 ? f[i - 1][j - 1][k] + w[i][1] : -1))
				// printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
			}
		}
	}

	int res = -1;
	for (int i = 1; i <= n + 1; i ++) {
		for (int j = 1; j < i; j ++) {
			int a = j - 1;
			int b = i - j;
			int c = n + 1 - i;
			if (a > n / 2 || b > n / 2 || c > n / 2) continue;
			res = max(res, f[n][a][b]);
		}
	}
	cout << res << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T; scanf("%d", &T);
	while (T --) solve();


	return 0;
}