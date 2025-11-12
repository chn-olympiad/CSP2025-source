#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 500005;
int n, s[MAXN], a[MAXN], cnt, cnt_0, cnt_1;
long long k;
vector<pair<int, int>> activity;
bool is_special = false;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (k == 1 || k == 0)is_special = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (is_special) {
			if (a[i] > 1)is_special = false;
			if (a[i] == 0)cnt_0++;
			else if (a[i] == 1)cnt_1++;
		}
		if (i == 1) {
			s[i] = a[i];
			continue;
		}
		s[i] = s[i - 1] ^ a[i];
	}
	if (is_special) {
		if (k == 1) {
			cout << cnt_1;
			return 0;
		} else if (k == 0) {
			int i = 1, now = 0;
			while (i <= n) {
				now = a[i];
				int res = 0;
				while (i <= n && a[i] == now) {
					++res;
					++i;
				}
				if (now == 1)cnt_0 += res/2;
			}
			cout << cnt_0;
			return 0;
		}
	}
	for (int l = 1; l <= n; ++l) {
		for (int r = l; r <= n; ++r) {
			int value = s[r] ^ s[l - 1];
			if (l == 1)value = s[r];
			if (value == k) {
				activity.push_back(make_pair(r, l));
			}
		}
	}
	sort(activity.begin(), activity.end());
	int latest = -0x3f3f3f3f;
	for (int i = 0; i < activity.size(); ++i) {
		int r = activity[i].first, l = activity[i].second;
		if (l <= latest)continue;
		// it's OK to add this activity
		latest = r;
		++cnt;
	}
	cout << cnt;
	return 0;
}
