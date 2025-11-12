#include<bits/stdc++.h>
using namespace std;

long long solve_value(int l, int r, const vector<long long>& a) {
	long long ans = a[l];
	for(int i = l + 1; i <= r; ++i) {
		ans ^= a[i];
	}
	return ans;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int>> right_list;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			if(solve_value(i, j, a) == k) {
				right_list.push_back({i, j});
			}
		}
	}
	sort(right_list.begin(), right_list.end(), cmp);
	//for(int i = 0; i < right_list.size(); ++i) cout << right_list[i].first << " " << right_list[i].second << "\n";
	long long final_ans = 0;
	if(right_list.empty()) {
		cout << final_ans;
		return 0;
	}
	int last_end = -1;
	for(int i = 0; i < right_list.size(); ++i) {
		if(right_list[i].first > last_end) {
			++final_ans;
			last_end = right_list[i].second;
		}
	}
	cout << final_ans;
	return 0;
}
