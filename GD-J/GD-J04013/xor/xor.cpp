#include <bits/stdc++.h>
#define pir pair<int,int>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], xora[maxn];
vector<pir> ps;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		xora[i] = xora[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if ((xora[i - 1] ^ xora[j]) == k) {
				ps.push_back({i, j});
			}
		}
	}
	int maxa = -1e9;
	for (int i = 0; i < ps.size(); ++i) {
		int l = ps[i].first;
		int r = ps[i].second;
		int ans = 1;
		for (int j = i + 1; j < ps.size(); ++j) {
			int l1 = ps[j].first;
			int r1 = ps[j].second;
			if (r < l1) {
				++ans;
				r = l1;
			}
		}
		maxa = max(ans, maxa);
	}
	cout << maxa;
}
