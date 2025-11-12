#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define DLN(x) cout << #x << "\t = " << x << '\n';
#define CDLN(x, l, r) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << (x[_IDX]) << ' '; cout << "]\n";
#define CCDLN(x, l, r, what) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << what << ' '; cout << "]\n";

using ll = long long;
template <typename T>
using vec = vector<T>;

// 60 pts

const int N = 1e3 + 10;

int arr[N], n, K;

int xors[N];

struct X {
	int l, r;
};

vector<X> whatever;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	scanf("%d%d", &n, &K);

	for (int i = 1; i <= n; i ++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i ++) {
		xors[i] = (xors[i - 1] ^ arr[i]);
	}

	for (int r = 1; r <= n; r ++) {
		for (int l = 1; l <= r; l ++) {
			if ((xors[r] ^ xors[l - 1]) == K) {
				whatever.push_back({ l, r });
				// cout << l << ' ' << r << '\n';
			}
		}
	}

	sort(whatever.begin(), whatever.end(), [](const X& a, const X& b) {
		if (a.r == b.r) return a.l > b.l;
		return a.r < b.r;
	});


	if (whatever.size() == 0) {
		puts("0");
		return 0;
	}

	int res = 1;
	X curr = whatever[0];
	for (int i = 1; i < whatever.size(); i ++) {
		if (whatever[i].l > curr.r) {
			curr = whatever[i];
			res ++;
		}
	}

	cout << res;

	return 0;
}
