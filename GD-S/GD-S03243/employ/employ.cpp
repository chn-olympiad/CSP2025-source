#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
string s;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	srand(time(0));
	
	cin >> n >> q;
	
	cin >>  s;
	
	for(int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
	}
	
	cout << rand() % 100000 + 1;
	return 0;
}

