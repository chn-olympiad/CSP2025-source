#include<bits/stdc++.h>
using namespace std;
typedef long long ll, i64;
typedef double db;
const int N = 1e4 + 5;

ll max(ll a, ll b) {
	if (a > b) return a;
	return b;
}

ll min(ll a, ll b) {
	if (a < b) return a;
	return b;
}

ll cmp_d(ll a, ll b) {
	return a > b;
}

map<string, string> rpl;//replace
ll n, q;

ll solve(string s) {
	
	
	
	
	
	return 0;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string inp1, inp2;
		cin >> inp1 >> inp2;
		rpl[inp1] = inp2;
	}
	while (q--) {
		string que = "";
		cin >> que;
		solve(que);
	}
	
	return 0;
}
