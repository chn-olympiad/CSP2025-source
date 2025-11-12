#include<bits/stdc++.h>
using namespace std;

long long dfs(int p, int n, const vector<int>& a, long long nowsum, vector<bool>& used_pos, int choose_numbers, int start_pos) {
	long long ans = 0;
	if(nowsum > n && choose_numbers >= 2) {
		++ans;
		ans %= 998244353;
	}
	for(int i = start_pos; i < p; ++i) {
		if(!used_pos[i]) {
			used_pos[i] = true;
			ans += dfs(p, n, a, nowsum + a[i], used_pos, choose_numbers + 1, i + 1);
			used_pos[i] = false;
		}
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long final_ans = 0;
	sort(a.begin(), a.end());
	for(int i = n - 1; i >= 2; --i) {
		vector<bool> used_pos(n, false);
		final_ans += dfs(i, a[i], a, 0, used_pos, 0, 0) % 998244353;
	}
	cout << final_ans;
	return 0;
}
