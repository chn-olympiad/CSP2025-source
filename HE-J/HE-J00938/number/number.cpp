#include<bits/stdc++.h>
#define up(i,l,r) for(ll i=l,E##i=r;i<=E##i;++i)
#define dn(i,l,r) for(ll i=l,E##i=r;i>=E##i;--i)
using namespace std;
typedef long long ll;
constexpr ll N = 5 + 1e6;

string s;
vector<char> a;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char const & c : s) {
		if (isdigit(c)) {
			a.push_back(c);
		}
	}
	sort(a.begin(), a.end(), greater<char>());
	cout << string(a.begin(), a.end());
	return 0;
}
