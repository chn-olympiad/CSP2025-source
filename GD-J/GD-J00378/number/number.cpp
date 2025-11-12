#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 1e6 + 5;
char s[N];
vector<int> v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> (s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		if (isdigit(s[i]))
			v.push_back(s[i] - '0');
	sort(v.begin(), v.end());
//	cerr << (v.size());
	if (v.back() == 0) cout << 0;
	else
		for (int i = v.size() - 1; i >= 0; --i) cout << v[i];
	return 0;
}
