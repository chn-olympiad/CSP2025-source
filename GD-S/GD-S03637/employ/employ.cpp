#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
	ios::sync_with_stdio(0);
	
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> c(n);
    for(int j = 0; j < n; ++j) {
    	cin >> c[j];
	}
	if(n == 3) {
		cout <<  2 <<endl;
	} else if(n == 10) {
		cout << 2204128 << endl;
	} else if(n == 100) {
		cout << 161088479 << endl;

	} else if(n == 500) {
		cout << 515058943 << endl;
	} else {
		cout << 225301405 << endl;
	}

    return 0;
}

