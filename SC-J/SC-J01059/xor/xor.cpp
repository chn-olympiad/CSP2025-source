#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
int n, k, a[N] = {}, pre[N] = {}, ans = 0;
vector< pair<int, int> > arr, tmp;
struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
	}
//	for (int len = 0; len <= n; len++) {
//		for(int i = 1; i + len <= n; i++) {
//			if ((pre[i + len] ^ pre[i - 1]) == k) {
////				printf("%d %d\n", i, i + len);
////				tmp.push_back({i, i + len});
//				ans++;
//			}
//		}
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((pre[j] ^ pre[i - 1]) == k) {
				tmp.push_back({i, j});
			}
		}
	}
	sort(tmp.begin(), tmp.end(), cmp());
	for (unsigned int i = 0; i < tmp.size(); i++) {
		if (arr.empty()) {
			arr.push_back(tmp[i]);
		}
		else if(arr.back().second < tmp[i].first) {
			arr.push_back(tmp[i]);
		}
	}
//	for (pii i : tmp) {
//		cout << i.first << ' ' << i.second << '\n';
//	}
	printf("%u", arr.size());
	return 0;
}