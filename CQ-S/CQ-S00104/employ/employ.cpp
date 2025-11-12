#include <bits/stdc++.h>

using namespace std;
const int MAXN = 505;
const int mod = 998244353;


int c,n,m;
string s;
int c1[MAXN];


int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	
	for(int i=1;i<=n;i++) {
		cin >> c1[i];
	}
	
	int res = 1;
	for(int i = n; i >= 1; i--) {
		res *= i; 
	}
	res %= mod;
	
	cout << res << endl;
	return 0;
}
