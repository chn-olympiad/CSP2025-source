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

const int N = 200;
int arr[N], n, m;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++) {
		scanf("%d", &arr[i]);
	}

	int t = arr[1];

	sort(arr + 1, arr + 1 + n * m, [](int a, int b) {
		return a > b;
	});

	int k = 1;
	for (int i = 1; i <= m; i ++) {
		if (i % 2 == 1) for (int j = 1; j <= n; j ++) {
			if (arr[k] == t) {
				printf("%d %d\n", i, j);
			}
			k ++;
		}
		else for (int j = n; j >= 1; j --) {
			if (arr[k] == t) {
				printf("%d %d\n", i, j);
			}	
			k ++;
		}
	}

	return 0;
}
