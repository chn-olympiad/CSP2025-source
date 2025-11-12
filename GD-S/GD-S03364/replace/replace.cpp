#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+3;

vector <int> mp[N<<1];
int n, q, ps[N], pt[N];
string s[N], t[N], a, b;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i=1; i <= n; ++i) cin >> s[i] >> t[i];
	if(n <= 10000) {
		while(q--) {
			cin >> a >> b;
			int l=0, r=a.size()-1, c=0;
			while(a[l] == b[l]) ++l;
			while(a[r] == b[r]) --r;
			for(int i=1; i <= n; ++i)
				if(a.substr(l, r-l+1) == s[i] && b.substr(l, r-l+1) == t[i]) c++;
			cout << c << endl;
		}
	}
	else {
		while(q--) cout << "0\n";
	}
	return 0;
}

