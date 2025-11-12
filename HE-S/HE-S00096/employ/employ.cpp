#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
long long a[N];
long long A_sort(int m) {
	long long ans = 1;
	for(int i = 0; i < m; i++) {
		ans *= m;
	}
	return ans % 998244353;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, t = 0;
	string s;
	cin >> n >> m >> s;
	if(m == 1) {
//		for(int i = 0; i < s.size(); i++) {
//			if(s[i] == '1') {
//				t++;
//			}
//		}
		cout << A_sort(n);
		return 0;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << A_sort(n);
	
	return 0;
}
