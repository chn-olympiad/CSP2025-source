#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
int n,m,a[50005];
const int mod = 998244353;
int read() {
	int ans = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1;c = getchar();}
	while (c >= '0' && c <= '9') {
		ans = ans*10+c-'0';
		c = getchar();
	}
	return ans*f;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int num = n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (!a[i]) num --;
	}
	if (num < m) {
		cout << 0;
		exit(0);
	}
	num = 1;
	for (int i = 2; i <= n; i ++) num = num*i%mod;
	cout << num;
	return 0;
}

