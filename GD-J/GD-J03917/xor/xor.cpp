#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, a[500001], f[500001];
struct Node {
	int l, r;
	bool operator < (const Node& A) const {
		if (r == A.r)
			return l > A.l;
		return r < A.r;
	}
};
vector<Node> v;
vector<int> p[1100001];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i] = (f[i - 1] ^ a[i]);
		p[f[i]].push_back(i);
	}
	for (int i = 0; i <= 1100000; i++)
		sort(p[i].begin(), p[i].end());
	for (int l = 1; l <= n; l++) {
		int x = (f[l - 1] ^ k), szz = p[x].size();
		if (!szz)
			continue;
		int ff = lower_bound(p[x].begin(), p[x].end(), l) - p[x].begin();
		if (ff == szz)
			continue;
		v.push_back({l, p[x][ff]});
	}
	sort(v.begin(), v.end());
	int mr = 0, sz = v.size(), cnt = 0;
	for (int i = 0; i < sz; i++)
		if (v[i].l > mr) {
			mr = max(mr, v[i].r);
			cnt++;
		}
	printf("%d", cnt);
	return 0;
}
