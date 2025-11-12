#include <bits/stdc++.h>
#define PII pair<int, int>
#define ll long long
#define ft first
#define sd second
#define mod 998244353
using namespace std;

const int N = 1e5 + 5;

int n, m;
char s[505];
int c[505];
void solve2() {
	ll sum1=1;
	for(int i=n;i>=1;i--) {
		sum1=sum1*i%mod;
	}
	cout <<((sum1)%mod+mod)%mod<<"\n";
	return ;
}
void solve() {
	bool f = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		f&=(s[i]=='1');
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if(f) {
		solve2();
		return ;
	}
	return ;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--) solve();
	return 0;	
}
