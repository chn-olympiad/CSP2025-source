//GZ-S00154 安顺市第一高级中学 张家豪

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int mod1 = 998;
	int mod2 = 244;
	int mod3 = 353;

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c[510];
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	unsigned long long ans = 1;
	for(int i = 0; i <= m - 1; i++) {
		ans = ans * (n - i);
		ans = ans % mod1;
		ans = ans % mod2;
		ans = ans % mod3;
	}

	cout << ans << endl;

}
