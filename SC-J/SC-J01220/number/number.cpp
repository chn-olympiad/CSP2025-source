#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using namespace std;
using P = pair<int, int>;
int tt;
namespace wangcy {
	const int N = 1e6 + 10;
	char ch[N];
	vector <int> v;
	int n;
	inline void Main() {
		cin >> (ch + 1), n = strlen(ch + 1);
		E(i, 1, n) {
			if(isdigit(ch[i])) v.emplace_back(ch[i] - '0');
		}
		stable_sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for(int x: v) {
			cout << x;
		}
		return cout << "\n", void();
	}
}
int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tt = 1;
	while(tt --) wangcy::Main();
	return 0;
}
// Ex : 100pts