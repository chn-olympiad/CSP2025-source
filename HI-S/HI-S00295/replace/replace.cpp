#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const long long P = 131, M = 1e12 + 7;
int n, q;
char s1[N], s2[N];
long long h1[N], h2[N], ha[N], hb[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s1 + 1);
		int len1 = strlen(s1+1);
		long long tmp1 = 0;
		for (int j = 1; j <= len1; j++) {
			tmp1 = tmp1 * P % M + (s1[j]-'a'+1);
		}
		scanf("%s", s2 + 1);
		int len2 = strlen(s2+1);
		long long tmp2 = 0;
		for (int j = 1; j <= len2; j++) {
			tmp2 = tmp2 * P % M + (s2[j]-'a'+1);
		}
		h1[i] = tmp1;
		h2[i] = tmp2;
	}
	while (q--) {
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		int len = strlen(s2 + 1);
		int len1 = strlen(s1 + 1);
		int l = 1, r = len, r1 = len1;
		while (s1[l] == s2[l]) {
			++l;
		}
		while (s1[r1] == s2[r]) {
			--r1;
			--r;
		}
		long long tmp1 = 0, tmp2 = 0;
		for (int i = l; i <= r1; i++) {
			tmp1 = tmp1 * P % M + (s1[i]-'a'+1);
		}
		for (int i = l; i <= r; i++) {
			tmp2 = tmp2 * P % M + (s2[i]-'a'+1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (tmp1 == h1[i] && tmp2 == h2[i]) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
