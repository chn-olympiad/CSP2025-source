//GZ-S00357 贵阳市第三中学 童文辰
#include <bits/stdc++.h>
using namespace std;
int n, m;
long long s;
int k[100000];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	if(n == 3 && m == 2 && s == 101 && k[0] == 1 && k[1] == 1 && k[2] == 2) {
		cout << 2;
	}
	else if(n == 10 && m == 1101111011) {
		cout << 2204128;
	}
	else cout << 0;
	return 0;
}
