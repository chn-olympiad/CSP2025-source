#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int, int> pr;
const int MAXN = 5e5 + 5;
int n, k;
int a[MAXN], sum[MAXN];
bool ONE = true, LYC = true, EWW = true;
vector<pr> hg;
namespace one { //10
	void solve() {
		printf("%d", n >> 1);
	}
};
namespace lyc { //15
	int ans = 0;
	void solve() {
		if (k) {
			for (int i = 1; i <= n; ++i)
				if (a[i])	++ans;
		} else {
			for (int i = 1; i <= n; ++i)
				if (!a[i])	++ans;
				else {
					if (a[i + 1]) {
						++ans;
						++i;
					}
				}
		}
		printf("%d", ans);
	}
};
bool cmp(pr x, pr y) {
	if (x.first != y.first)	return x.first < y.first;
	else	return x.second < y.second;
}
namespace eww { //unknown, incorrect (probably 0)
	// xorsum[l, r] = sum[r] xor sum[l - 1]
	LL ans = 0;
	void solve() {
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j)
				if ((sum[j] ^ sum[i - 1]) == k)
					hg.emplace_back(i, j);
		sort(hg.begin(), hg.end(), cmp);
		int t = 1;
		for (auto i : hg) {
			int l = i.first, r = i.second;
			if (l >= t) {
				++ans;
				t = r + 1;
			}
		}
		printf("%lld", ans);
	}
};
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum[i] = (sum[i - 1] ^ a[i]);
		if (a[i] != 1)	ONE = false;
		if (a[i] > 1)	LYC = false;
		if (a[i] > 255)	EWW = false;
	}
	if (ONE)	one::solve();
	else if (LYC)	lyc::solve();
	else if (EWW)	eww::solve();
	return 0;
}