#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2e3 + 5; 

int n, q;
int L1, L2;
int len[MAXN];
char s[MAXN][2][MAXN], t[2][MAXN];
int pi[2][MAXN];
int pre[MAXN], suf[MAXN];
char ss[MAXN * MAXN];

int main(void) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s %s", s[i][0], s[i][1]);
		len[i] = strlen(s[i][0]);
		L1 += len[i];
	}
	for (int Case = 1; Case <= q; ++Case) {
		scanf("%s %s", t[0], t[1]);
		int Len = strlen(t[0]);
		pre[0] = (t[0][0] == t[1][0]);
		for (int i = 1; i < Len; ++i)
			pre[i] = pre[i - 1] && (t[0][i] == t[1][i]);
		suf[Len - 1] = (t[0][Len - 1] == t[1][Len - 1]);
		for (int i = Len - 2; i >= 0; --i)
			suf[i] = suf[i + 1] && (t[0][i] == t[1][i]);
//		for (int i = 0; i < Len; ++i)
//			printf("%d%c", pre[i], " \n"[i == Len - 1]);
//		for (int i = 0; i < Len; ++i)
//			printf("%d%c", suf[i], " \n"[i == Len - 1]);
		int ans = 0;
		for (int id = 1; id <= n; ++id) {
			sprintf(ss, "%s$%s", s[id][0], t[0]);
			int LL = strlen(ss);
			pi[0][0] = 0;
//			printf("ss = %s\n", ss);
//			printf("s[%d][0] = %s\n", id, s[id][0]);
			for (int i = 1; i < LL; ++i) {
				int j = pi[0][i - 1];
				while (j && ss[i] != ss[j])
					j = pi[0][j - 1];
				if (ss[i] == ss[j])
					++j;
				pi[0][i] = j;
			}
//			for (int i = 0; i < LL; ++i)
//				printf("%d%c", pi[0][i], " \n"[i == LL - 1]);
			sprintf(ss, "%s$%s", s[id][1], t[1]);
			pi[1][0] = 0;
			for (int i = 1; i < LL; ++i) {
				int j = pi[1][i - 1];
				while (j && ss[i] != ss[j])
					j = pi[1][j - 1];
				if (ss[i] == ss[j])
					++j;
				pi[1][i] = j;
			}
			bool OK = false;
			for (int i = len[id] + 1; i < LL; ++i) {
				if (pi[0][i] == len[id] && pi[1][i] == len[id] &&
					pre[i - len[id] - len[id]] && suf[i - len[id] + 1]) {
						OK = true;
						break;
					}
			}
			if (OK)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
