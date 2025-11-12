#include <iostream>
#include <vector>
#include <string>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)
#define repi(i, begin, end) for (int i = begin; i <= end; i += 1)
#define rep1(i, n) repi(i, 1, n)

using namespace std;
using llu = long long unsigned;
const llu MOD = 998244353;
const bool debugm = true;

void set_io() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}


int main() {
	set_io();
	
	int n, m;
	cin >> n >> m;
	
	string str;
	cin >> str;
	
	vector<bool> s(n);
	int ccnt = 0;
	
	rep(i, n) {
		s[i] = (str[i] == '1');
		ccnt += s[i];
	}
	
	vector<int> c(n);
	int cnt = 0;
	
	rep(i, n) {
		cin >> c[i];
		
		if (c[i] != 0) {
			cnt += 1;
		}
	}
	
	if (cnt < m || ccnt < m) {
		cout << 0 << endl;
		return 0;
	}
	
	llu res = 1;
	rep1(i, n) {
		res *= i;
		res %= MOD;
	}
	
	cout << res << endl;
	return 0;
}
