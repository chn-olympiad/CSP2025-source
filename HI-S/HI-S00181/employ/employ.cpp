#include <bits/stdc++.h>
using namespace std;
int a[1003];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans = 1;
	for (int i = 1;i <= n;i++){
		ans *= i;
		ans = ans % 998244353;
	}
	cout << ans;
	return 0;
}

