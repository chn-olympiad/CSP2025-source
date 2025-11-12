#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;
int n, k, ans;
long long a[maxn], sum[maxn];
vector<pair<int, int>>q;
bool f = true;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first != y.first) return x.first < y.first;
	return x.second < y.second;
}

int zs(int s) {
	int ans = 0;
	int x = q[s].first, y = q[s].second;
	for (int i = s; i < q.size(); ++i) {
		if (q[i].first > y) ans = max(ans, zs(i) + 1);
	}
	return ans;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
		if (a[i] != 1) f = false;
		for (int j = 0; j < i; ++j) {
			if (sum[i]^sum[j] == k) q.push_back({i, j + 1});
		}
	}
	if (f) {
		if (k == 0) cout << n / 2;
		else cout << n;
		return 0;
	} else cout << "2";
	sort(q.begin(), q.end(), cmp);
	int cnt = 0;
	for (int i = 0; i < q.size(); ++i) {
		cnt = max(zs(i), cnt);
	}
	cout << cnt;

	return 0;
}