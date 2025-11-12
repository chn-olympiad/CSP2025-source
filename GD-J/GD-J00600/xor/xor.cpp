#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N], sum[N];
vector<pair<int, int>> v;

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((sum[j] ^ sum[i - 1]) == k) {
				v.push_back({i, j});
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	int last = -1, cnt = 0;
	for (pair<int, int> p : v) {
		if (p.first > last) {
			cnt++;
			last = p.second;
		}
	}
	cout << cnt << endl;
	return 0;
}
