#include<bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 998244353;

void coder() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	ll ans = 1;
	for (ll i = 1; i <= n; ++i) {
		ans = ans * i % mod;
		int a;
		cin >> a;
	}
	cout << ans;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	coder();
	
	return 0; 
}
