#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 1e5+5;
const int MOD = 998244353;

int n,m;
string s;
int c[N];

ll specialA() {
	ll ans = 1;
	int ln = n;
	for(int i=1; i <= n; i++) {
		if(c[i] == 0) ln -= 1;
	}
	for(int i=ln; i >= ln-m+1; i--) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans;
}

void solve() {
	cin >> n >> m;
	cin >> s;
	for(int i=1; i <= n; i++) {
		cin >> c[i];
	}
	
	specialA();
	return;
}

signed main() {
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
//	cin >> T;
	
	while(T--) {
		solve();
	}
	
	return 0;
}
