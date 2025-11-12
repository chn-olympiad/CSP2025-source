#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> res;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	string str; cin >> str;
	
	for (auto val : str) 
		if (isdigit(val)) res.emplace_back(val - '0');
	
	sort(res.begin(), res.end(), greater<int>());
	
	while (res.front() == 0 && res.size() > 1) res.erase(res.begin()); 
	
	for (auto val : res) cout << val;
	
	return 0;
}