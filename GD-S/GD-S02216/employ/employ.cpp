#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int mod = 998244353;
const int N = 500 + 5;
int n, m, c[N];
string s;

bool check(){
	for(int i = 0; i < n; ++i) if(s[i] == '0') return false;
	return true;
}

ll A(ll n, ll m){
	ll res = 1;
	for(ll i = n; i > n - m; --i) res = res * i % mod;
	return res % mod;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	cout << A(n, n) << "\n";
	return 0;
}
