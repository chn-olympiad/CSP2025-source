#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e5 + 10;
const int MOD = 998244353;
string s;
vector <int> a;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	Write by Na1L0n9
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			a.push_back(s[i] - '0');
		}
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i : a) {
		cout << i;
	}
	return 0;
}

// ccf牛逼，我刚学OI91天，居然会做T1，感谢ccf 
