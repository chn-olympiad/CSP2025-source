#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 2;
const int M = 1e6 + 2;
int n, k, a[N], sum[N], tot, rr, cnt = 1, p, j;
struct Segment {
	int l, r;
	bool operator < (const Segment &cmp) const {
		return r < cmp.r;
	}
} seg[M];
struct Xorsum {
	int summ, idx;
	bool operator < (const Xorsum &cmp) const {
		if (summ != cmp.summ) {
			return summ < cmp.summ;
		}
		return idx < cmp.idx;
	}
} xsum[N];
int Find(int tsum) {
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (tsum < xsum[mid].summ) {
			r = mid - 1;
		} else if (tsum == xsum[mid].summ) {
			return mid;
		} else {
			l = mid + 1;
		}
	}
	return -1;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		xsum[i].summ = sum[i] ^ k, xsum[i].idx = i;
	}
	sort(xsum + 1, xsum + n + 1);
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			if ((sum[j] ^ sum[i - 1]) == k) {
//				seg[++tot] = {i, j};
//				break;
//			}
//		}
//	}
	for (int i = 1; i <= n; i++) {
		int idx = Find(sum[i - 1]);
//		printf("%d\n", idx);
//		printf("Find=%d Found=%d Found_idx=%d\n", sum[i - 1], xsum[idx].summ, xsum[idx].idx);
		if (idx == -1) {
			continue;
		}
		if (xsum[idx].idx >= i) {
			while (xsum[idx - 1].idx >= i && xsum[idx - 1].summ == sum[i - 1]) {
				idx--;
			}
		} else {
			while (xsum[idx].idx < i && xsum[idx + 1].summ == sum[i - 1]) {
				idx++;
			}
		}
		if (xsum[idx].idx < i) {
			continue;
		}
		seg[++tot] = {i, xsum[idx].idx};
//		printf("l=%d r=%d\n", i, xsum[idx].idx);		
	}
	sort(seg + 1, seg + tot + 1);
	if (!tot) {
		return 0 * puts("0");
	}
	rr = seg[1].r, p = 1;
	while (p + 1 <= tot) {
		p++;
		if (seg[p].l > rr) {
			rr = seg[p].r, cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
