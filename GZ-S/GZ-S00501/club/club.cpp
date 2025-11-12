// 准考证：GZ-S00501，姓名：黄佳洛，学校：华中师大一附中贵阳学校 

#include <bits/stdc++.h>
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define IO ios::sync_with_stdio(0)
#define PII pair<int, int>
#define int long long
#define x first
#define y second

using namespace std;

const int N = 1e6 + 10;

int n, m;
int w[N][3];
PII a[N], b[N], c[N];

inline void solve() {
	cin >> n;
	int res = 0, idx1 = 0, idx2 = 0, idx3 = 0;
	upp(i, 1, n) {
		cin >> w[i][1] >> w[i][2] >> w[i][3];
		int maxn = max(w[i][1], max(w[i][2], w[i][3]));
		res += maxn;
		if (maxn == w[i][1]) a[++idx1] = {maxn - max(w[i][2], w[i][3]), i};
		else if (maxn == w[i][2]) b[++idx2] = {maxn - max(w[i][1], w[i][3]), i};
		else c[++idx3] = {maxn - max(w[i][2], w[i][1]), i};
	}
	
	if (idx1 > n / 2) {
		sort(a + 1, a + idx1 + 1);
		upp(i, 1, idx1) {
			idx1--;
			res = res - w[a[i].y][1] + max(w[a[i].y][2], w[a[i].y][3]);
			if (idx1 == n / 2) break;
		}
	}
	if (idx2 > n / 2) {
		sort(b + 1, b + idx2 + 1);
		upp(i, 1, idx2) {
			idx2--;
			res = res - w[b[i].y][2] + max(w[b[i].y][1], w[b[i].y][3]);
			if (idx2 == n / 2) break;
		}
	}
	if (idx3 > n / 2) {
		sort(c + 1, c + idx3 + 1);
		upp(i, 1, idx3) {
			idx3--;
			res = res - w[c[i].y][3] + max(w[c[i].y][2], w[c[i].y][1]);
			if (idx3 == n / 2) break;
		}
	}
	
	cout << res << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	IO;
	int T;
	cin >> T;
	while (T--) solve(); 
	
	return 0;
}

/*
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
