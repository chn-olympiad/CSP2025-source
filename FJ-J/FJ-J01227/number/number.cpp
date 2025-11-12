#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)

using namespace std;

typedef long long ll;
typedef string str;

str s;
std::vector<int> v;

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	F(i, 0, n - 1, 1) {
		if (isdigit(s[i])) {
			v.push_back(s[i] - '0');
		}
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	n = v.size();
	F(i, 0, n - 1, 1) {
		cout << v[i];
	}
	cout << el;
	r0;
}
