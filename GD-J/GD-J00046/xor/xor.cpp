#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
vector<int> v;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, l, r, cnt = 0;
	bool ok;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	l = 1;
	for (r = 1; r <= n; r++) {
		ok = false;
		for (auto &it: v)
			if ((int) (it ^ a[r]) == k) {
				l = r + 1;
				cnt++;
				ok = true;
				v.clear();
				break;
			} else it ^= a[r];
		if (!ok) {
			if (a[r] == k) {
				cnt++;
				l = r + 1;
				v.clear();
			} else v.push_back(a[r]);
		}
	}
	printf("%d", cnt);
	return 0;
}
