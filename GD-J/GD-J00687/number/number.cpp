//------------------------RP += INF!-------------------------------------
//RootSign WILL BE UNSTOPPABLE!
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> a;
	a.reserve(n);
	for (int i = 0; i < n; ++i) {
		if (isdigit(s[i])) a.push_back(s[i] - '0');
	}
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < (int)a.size(); ++i) {
		cout << a[i];
	}
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
