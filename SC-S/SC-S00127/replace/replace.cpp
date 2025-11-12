#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e5 + 5;

int n, q, ans;
bool flag = false;
int len1, len2, Len1[N], Len2[N];
string t1, t2, s1[N], s2[N];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	// 输入
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> s1[i] >> s2[i];
		// 存储
		Len1[i]  = s1[i].size(), Len2[i] = s2[i].size();
	}
	while(q--) {
		// 输入
		cin >> t1 >> t2;
		// 存储
		ans = len1 = len2 = 0;
		flag = false;
		len1 = t1.size(), len2 = t2.size();
		// 排序
		// 处理
		for(int i = 0; i < len1; i ++) {
			for(int j = 1; j <= n; j ++) {
				for(int k = 0; k < Len1[j]; k ++) {
					if (t1[i] == s1[j][k]) {
						flag = true;
					} else {
						flag = false;
					}
				}
				if(flag == true) {
					ans++;
				}
				flag = false;
			}
		}
		// 输出
		cout << ans << endl;
	}
	return 0;
}