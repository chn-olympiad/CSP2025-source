#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)



const int mod = 7 + 1e9;
const int N = 3 + 2e5;

mt19937 rnd(time(NULL));

int main() {
//	freopen("D:\\work\\number\\number4.in", "r", stdin);
//	freopen("D:\\work\\number\\number4.out", "w", stdout);	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	string ans;
	for (auto i : s) {
		if (isdigit(i)) {
			ans += i;
		}
	} 
	sort(ans.rbegin(), ans.rend());
	cout << ans;
	
	return 0;
} 