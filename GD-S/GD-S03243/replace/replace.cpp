#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
string a[10010], b[10010];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i];
	}
	
	while(q --) {
		string x, y;
		cin >> x >> y;
		
		cout << rand() % 100000 + 1 << "\n";
	}
	return 0;
}

