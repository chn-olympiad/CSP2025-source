#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
#define fst first
#define snd second
using namespace std;
const int MAX=2e5+10;
int t=1, n, q;
pair<string, string> str[MAX], qst;
ll ans;
void init() {

}
void exe() {
	for (int i=1;i<=n;i++) cin >> str[i].fst >> str[i].snd;
	while (q--) {
		ans=0;
		cin >> qst.fst >> qst.snd;
		for (int i=1;i<=n;i++) {
			int siz=str[i].fst.size();
			string tmp;
			for (int j=0;j+siz-1<qst.fst.size();j++) {
				string tmp2;
				for (int k=j;k<j+siz;k++) tmp2.push_back(qst.fst[k]);
				if (tmp2==str[i].fst) {
					string tmp1=tmp+str[i].snd;
					for (int k=j+siz;k<qst.fst.size();k++) tmp1.push_back(qst.fst[k]);
					ans+=tmp1==qst.snd;
				}
				tmp.push_back(qst.fst[j]);
			}
		}
		printf("%lld\n", ans);
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &q);
		init();
		exe();
	}
	return 0;
}
