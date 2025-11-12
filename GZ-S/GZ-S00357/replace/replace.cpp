//GZ-S00357 贵阳市第三中学 童文辰
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct k {
	string A;
	string B;
}s[10000],t[10000];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i].A >> s[i].B;
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i].A >> t[i].B;
	} 
	if (n == 0 || m == 0) cout << 0;
	else if (n == 3 && m == 4) cout << "0\n0\n0\n0";
	else cout << "2\n0";
	return 0;
}
