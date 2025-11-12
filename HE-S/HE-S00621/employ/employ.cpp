#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans = 1;
string s;
int main() {
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++) {
		int x;
		cin >> x;
	}
	for(int i = m;i;i--) {
		ans = ans * n % 998244353;
		n--;
	}
	cout << ans << endl;
	return 0;
}
