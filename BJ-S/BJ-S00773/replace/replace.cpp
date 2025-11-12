#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2e5+5,K = 998244353;
string s[N][2],c[2];
int n,m,cnt = 0;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> s[i][0] >> s[i][1];
	}
	while (m--) {
		cin >> c[0] >> c[1];
		if (c[0].size() != c[1].size()) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < c[0].size();j++) {
				bool flag = 1;
				for (int k = 0;k + j < c[0].size() && 
				k < s[i][0].size();k++) {
					if (c[1][k + j] != s[i][0][k] || s[i][0][k] != c[0][k + j]) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					cnt++;
					cnt %= K;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}