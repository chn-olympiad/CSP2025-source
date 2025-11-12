#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int pre[maxn];
struct node {
	int l, r;
};
vector<node> fkCCF;
bool cmp(node x, node y) {
	if (x.l != y.l) return x.l < y.l;
	return x.r - x.l < y.r - y.l;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		int _;
		cin >> _;
		pre[i] = pre[i - 1] ^ _;
		for (int j = i; j >= 1; j --) {
			if ((pre[i] ^ pre[j - 1]) == k) {
				fkCCF.push_back({j, i});
				break;
			}
		}
	}
	sort(fkCCF.begin(), fkCCF.end(), cmp);
	int ans = 0, now = 0;
	for (int i = 0; i < fkCCF.size(); i ++) {
		auto x = fkCCF[i];
		if (now < x.l) {
			int sum = 0, idx = 0;
			for (int j = i + 1; fkCCF[j].l <= x.r && j < fkCCF.size(); j ++) {
				if (fkCCF[j].r <= x.r) sum ++, idx = j;
			}
			if (idx) {
				ans += sum;
				now = fkCCF[idx].r;
			}
			else {
				ans ++, now = x.r;
			}
		}
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


