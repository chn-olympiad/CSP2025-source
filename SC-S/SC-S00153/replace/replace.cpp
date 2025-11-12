#include <bits/stdc++.h>
#define ull unsigned long
using namespace std;
const int maxn = 2e5;
const ull p = 131;
int n,q;
string s1[maxn + 5],s2[maxn + 5];
ull h1[maxn + 5],h2[maxn + 5];
ull H(string s) {
	ull ans = 0;
	for (int i = 0;i < (int)s.size();i ++) ans = ans * p + (ull)(s[i]);
	return ans;
}
int main() { // baoli
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i = 1;i <= n;i ++) {
		cin >> s1[i] >> s2[i];
		h1[i] = H(s1[i]);
		h2[i] = H(s2[i]);
	}
	while (q --) {
		string t1,t2;
		cin >> t1 >> t2;
		ull ht = H(t1),tar = H(t2);
		int ans = 0;
		int lent = t1.size();
		for (int i = 1;i <= n;i ++) {
			int lens = s1[i].size();
			for (int j = 0;j + lens - 1 < lent;j ++) { // 替换[j,j + lens - 1];
				if (j > 0 && t1[j - 1] != t2[j - 1]) break;
				int pos = j + lens;
				for (int k = j,l = 0;k <= j + lens - 1;k ++,l ++) {
					if (s1[i][l] != t1[k] || s2[i][l] != t2[k]) {
						pos = -1;
						break;
					}					
				}
				if (pos != -1) {
					bool flag = true;
					for (int k = pos;k < lent;k ++) {
						if (t1[k] != t2[k]) {
							flag = false;
							break;
						}
					}
					if (flag) {
						ans ++;
//						printf("f%d[%d,%d]\n",i,j,j + lens - 1);
					}
				}
			}
		}
		printf("%d\n",ans);
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