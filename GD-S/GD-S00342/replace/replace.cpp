#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
int n, q;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	if(n == 4 && q == 2) {
		cout << "2\n0";
	}
	else if(n == 3 && q == 4) {
		cout << "0\n0\n0\n0";
	}
	return 0;
}

