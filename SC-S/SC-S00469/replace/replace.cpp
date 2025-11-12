#include <bits/stdc++.h>
#define get1(l, r) pre1[r] - fact[r - l + 1] * (l ? pre1[l - 1] : 0)
#define get2(l, r) pre2[r] - fact[r - l + 1] * (l ? pre2[l - 1] : 0)
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 10, M = 5e6 + 10, V = 2000000, P = 13331;
int n, m, len[N];
ull a[N], b[N], pre1[N], pre2[N], fact[N];
char s1[N], s2[N];
bool f[N], pre[N], suf[N];
void solve() {
	fact[0] = 1;
	for(int i = 1; i < N; i ++) fact[i] = fact[i - 1] * P;
	for(int i = 0; i < n; i ++) {
		scanf("%s%s", s1, s2);
		len[i] = strlen(s1);
		for(int j = 0; s1[j]; j ++) a[i] = a[i] * P + (s1[j] - 'a');
		for(int j = 0; s2[j]; j ++) b[i] = b[i] * P + (s2[j] - 'a');
	}
	while(m --) {
		scanf("%s%s", s1, s2);
		int len1 = strlen(s1), len2 = strlen(s2);
		if(len1 != len2) {
			puts("0");
			continue;
		}
		for(int i = 0; i < len1; i ++) {
			pre1[i] = (i ? pre1[i - 1] : 0) * P + (s1[i] - 'a');
			pre2[i] = (i ? pre2[i - 1] : 0) * P + (s2[i] - 'a');
			f[i] = s1[i] != s2[i];
		}
		for(int i = 0; i < len1; i ++) pre[i] = (i ? pre[i - 1] : false) | f[i];
		suf[len1] = false;
		for(int i = len1 - 1; ~i; i --) suf[i] = suf[i + 1] | f[i];
		int cnt = 0;
		for(int i = 0; i < len1; i ++) {
			for(int j = 0; j < n; j ++)
				if(i + len[j] <= len1) {
					if(i && pre[i - 1]) continue;
					if(suf[i + len[j]]) continue;
					if(get1(i, i + len[j] - 1) == a[j] && get2(i, i + len[j] - 1) == b[j]) cnt ++;
				}
		}
		printf("%d\n", cnt);
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &m);
	solve();
	return 0;
}