#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 500 + 10;
const ll P = 998244353;
int n, m;
ll ans = 1;
string s;
int c[N];
int t[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
		t[c[i]]++;
	}
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') {
			return cout << "0\n", 0;
		}
	}
	for(int i = 1; i <= n; ++i) {
		ans = (ans * i) % P;
	} 
	cout << ans << "\n";
	return 0;
}

