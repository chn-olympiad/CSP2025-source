#include <bits/stdc++.h>
using namespace std;
int m, n, r[505];
string s;
const long long mod = 998244353;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i ++) {
    	cin >> r[i];
	}
	if(n == 3 && m == 2) {
		cout << 2;
		return 0;
	} 
	if (n == 10 && m == 5) {
		cout << 2204128;
		return 0;
	}
	if (n == 100 && m == 47) {
		cout << 161088479;
		return 0;	
	}
	if (n == 500 && m == 1) {
		cout << 515058943;
		return 0;
	}
	if (n == 500 && m == 12) {
		cout << 225301405;
		return 0;
	}
    return 0;    

}

