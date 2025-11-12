#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
//vector<bool> into2 (int x) {
//	vector<bool> bl;
//	while(x) {
//		x >>= 1;
//		bl.push_back(x & 1);
//	}
//	bl.pop_back();
//	reverse(bl.begin(), bl.end());
//	return bl;
//}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt0 = 0, cnt1 = 0;
	cin >> n >> k;
//	vector<bool> kk = into2(k);

	vector<int> a(n);
	vector<pii> ans;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] == 0) cnt0++;
		else if(a[i] == 1) cnt1++;
	}
	if(k == 1) {
		cout << cnt1 << '\n';
		return 0;
	}	
	else if(k == 0) {
		cout << cnt0 + cnt1 / 2 << '\n';
		return 0;
	}
	for(int l = 0; l < n; ++l) { // [l, r)
		for(int r = l + 1; r <= n; ++r) {
			int xo = 0;
			for(int i = l; i < r; ++i) {
				xo ^= a[i];
			}
			if(xo == k) ans.push_back({l, r - 1});
		}
	}

	sort(ans.begin(), ans.end(), [&] (const pii x, const pii y) {
		return x.second - x.first < y.second - y.first;
	});
//	for(auto& i : ans) {
//		cout << i.first << ' ' << i.second << '\n';
//	}
	int res = 0;
	vector<bool> used(n, false);
	for(int i = 0; i < ans.size(); ++i) {
		bool flag = true;
		for(int l = ans[i].first, r = ans[i].second; l <= r; ++l) {
			if(used[l]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			for(int l = ans[i].first, r = ans[i].second; l <= r; ++l) {
				used[l] = true;
			}
			res++;
		}
		
	}
	cout << res << '\n'; 
	return 0;
}
