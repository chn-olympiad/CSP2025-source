#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
const long long MOD = 998244353;
long long a[N];
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	cout << (n * (n + 1) / 2 + MOD) % MOD;
	return 0;
}
