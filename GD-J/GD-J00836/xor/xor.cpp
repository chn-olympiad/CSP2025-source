#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 5e5 + 3;
const int T = 1 << 20;

vector<int> vec[T];

pair<int, int> tmp[N]; 
int a[N], dp[N], c[N], sz[T];
int n, k;

void modify (int x, int y) {
	for (int i = x; i <= n; i += i & (-i)) c[i] = max(c[i], y);
}

int calc (int x) {
	int res = 0;
	for (; x; x -= x & (-x)) res = max(res, c[x]);
	return res;
}

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
	for (int i = 1; i <= n; i++) { vec[a[i]].push_back(i); ++sz[a[i]]; }
	int tot = 0;
	for (int i = 0; i <= n; i++) {
		int val = a[i] ^ k;
		if (!sz[val]) continue;
		int L = -1, R = sz[val];
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if (vec[val][M] <= i) L = M;
			else R = M;
		}
		if (R < sz[val]) tmp[++tot] = make_pair(vec[val][R], i);
	}
	sort(tmp + 1, tmp + tot + 1);
	for (int i = 1; i <= tot; i++) {
		int r = tmp[i].first, l = tmp[i].second;
		dp[r] = max(dp[r], calc(l) + 1);
		modify(r, dp[r]);
	}
	printf("%d\n", calc(n));
}
