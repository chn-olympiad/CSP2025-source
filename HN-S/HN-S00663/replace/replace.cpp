#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5001000;
int n, q;
char s[N], t[N];
string S[N], T[N];

int main() {
	freopen("replace.in", "r", stdin);freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", s + 1, t + 1);
		S[i]=s+1;
		T[i]=t+1;
	}
	for (int i = 1; i <= q; i++) {
		scanf("%s%s", s + 1, t + 1);
		int lens = strlen(s + 1), lent = strlen(t + 1);
		if (lens != lent) {
			puts("0");
		} else {
			string ss = s +1, tt=t+1;
			int ans = 0;
			for (int j = 1; j <= n; j++) if (S[j].size() <= lens) {
				for (int l = 0; l <= lens - S[j].size(); l++) {
					if (ss.substr(l,S[j].size())==S[j]){
						// continue;
						string sss = ss.substr(0,l)+T[j]+ss.substr(l+S[j].size());
						if (sss==tt) {
							ans++;
						}
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}