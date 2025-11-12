#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;

using namespace std;

string s;
vector<int> var;

void Debug() {

}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (isdigit(s[i])) var.push_back(s[i] - '0');
	}
	sort(var.begin(), var.end(), greater<int>());
	for (const auto &it : var) cout << it;
	cout << '\n';
	return 0;
}