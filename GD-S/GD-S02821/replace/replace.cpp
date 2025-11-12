#include <bits/stdc++.h>
using namespace std;
int n, q, ans, num[110];
string s1, s2;
unsigned long long hs[110][2], k = 9486531, pre[2010] = {1}, n1[210], n2[210];
void tH(string s, int id, int sp){
	for (int i = 1, l = s.size(); i <= l; i ++)
		hs[id][sp] = hs[id][sp] * k + s[i - 1];
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= 2001; i ++)pre[i] = pre[i - 1] * k;
	for (int i = 1; i <= n && cin >> s1 >> s2; i ++)
		tH(s1, i, 0), tH(s2, i, 1), num[i] = s1.size();
	while (q -- && cin >> s1 >> s2){
		ans = 0;
		for (int i = 1, l = s1.size(); i <= l; i ++)
			n1[i] = n1[i - 1] * k + s1[i - 1];
		for (int i = 1, l = s2.size(); i <= l; i ++)
			n2[i] = n2[i - 1] * k + s2[i - 1];
		for (int i = 1; i <= n; i ++){//每一对二元组
			for (int j = 1, l = s1.size(); j + num[i] - 1 <= l; j ++){//起始位置
				if (n1[j + num[i] - 1] - n1[j - 1] * pre[num[i]] == hs[i][0] &&
				n2[j + num[i] - 1] - n2[j - 1] * pre[num[i]] == hs[i][1] &&
				n1[j - 1] == n2[j - 1] && n1[l] - n1[j + num[i] - 1] * pre[l - j - num[i] + 1] ==
				n2[l] - n2[j + num[i] - 1] * pre[l - j - num[i] + 1])ans ++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
