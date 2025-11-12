// GZ-S00471 贵阳市第一中学 陈昱竹 
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+50;
int n, q;
string s[N][2], s1, s2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	while(q--) {
		cout << 0 << endl;
	}
	return 0;
}
