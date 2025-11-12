#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
string s[N][2], t[N][2];
int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i ++) {
		cin >> t[i][0] >> t[i][1];
	}
	for (int i = 0; i < q; i ++) {
		cin >> s[i][0] >> s[i][1];
		int ans = 0;
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < s[i][0].size() - t[j][0].size(); k ++) {
				cout << s[i][0][k] << ' ' << t[j][0][0]<< endl;
				if (s[i][0][k] == t[j][0][0]) {
					cout <<s[i][0].replace (k, t[j][0].size(), t[j][1]) <<endl;
					if(s[i][0].replace (k, t[j][0].size(), t[j][1]) == s[i][1]) ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
//拿不到1=会死吗
//不知道说什么好
//还有三分钟
//但是我没得挣扎了
//T1卡了之后重构两次
//然后发现T2最小生成树（应该 
//其实已经忘干净了
//但是前天某人又让我写了一次
//印象不深但是大致记得
//然后怎么就挂了
//算了T2能拿多少算多少
//按理来说本来我写不出来的 
//所以
//感谢chenxi2009 
