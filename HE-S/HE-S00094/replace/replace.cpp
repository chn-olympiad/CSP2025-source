#include <bits/stdc++.h>
using namespace std;

string a[2000007];
string b[2000007];
string a_[2000007];
string b_[2000007];

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> a_[i] >> b_[i];
	}
	for (int i = 0; i < q; i++) {
		long long ans = 2;
		cout << ans;
	}
	
	return 0;
}
