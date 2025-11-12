#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	vector<int> a;
	int n = s.size();
	for (int i = 0; i < n; i++) {
        int tmp = (s[i] - '0');
        if (tmp >= 0 && tmp <= 9) a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	n = a.size() - 1;
	for (int i = n; i >= 0; i--) cout << a[i];

	return 0;
}
