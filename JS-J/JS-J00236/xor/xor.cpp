// JS-J00236
// XD

#include<bits/stdc++.h>
using namespace std;
int n, k, ans = 0, x;
map<pair<int, int>, int> dp;
vector<pair<int, int> > ve;
map<int, bool> vis;
bool cmp(pair<int, int> x, pair<int, int> y){
	return (x.second - x.first + 1) < (y.second - y.first + 1);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> x;
		for (int j = 1; j <= i; ++j){
			dp[{j, i}] = dp[{j, i - 1}] ^ x;
			if (dp[{j, i}] == k){
				ve.push_back({j, i});
			}
		}
	}
	sort(ve.begin(), ve.end(), cmp);
	for (int i = 0; i < ve.size(); ++i){
		bool flag = 0;
		for (int j = ve[i].first; j <= ve[i].second; ++j){
			if (vis[j]){
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		++ans;
		for (int j = ve[i].first; j <= ve[i].second; ++j){
			vis[j] = 1;
		}
	}
	cout << ans;
	return 0;
}
