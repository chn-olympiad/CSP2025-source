#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string str;
vector<int> v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			v.push_back(str[i] - '0');
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
	cout << '\n';
	return 0;
}
