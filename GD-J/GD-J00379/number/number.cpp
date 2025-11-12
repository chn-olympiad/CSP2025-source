#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
string s;
vector <ll> v;
bool cmp (ll x, ll y) {
	return x > y;
}
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size (); ++ i) {
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back (s[i] - '0');
		}
	}
	sort (v.begin (), v.end (), cmp);
	for (int i = 0; i < v.size (); ++ i) cout << v[i];
	cout << '\n';
	return 0;
}
