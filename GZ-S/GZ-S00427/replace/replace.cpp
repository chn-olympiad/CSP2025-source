// GZ-S00427 安顺二中 赵沿凯 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (a); i <= (b); ++ i)

const int N = 3e3 + 10;
int n, Q, p1[N], p2[N];
char s1[N][N], s2[N][N], t1[N], t2[N];

void sub0() {
	FOR(i, 1, n) scanf("%s", s1[i] + 1), scanf("%s", s2[i] + 1);
	while(Q --) {
		scanf("%s", t1 + 1), scanf("%s", t2 + 1);
		if(strlen(t1 + 1) != strlen(t2 + 1)) { printf("0\n"); continue; } 
		int cnt = 0;
		FOR(i, 1, n) {
			int s1len = strlen(s1[i] + 1), t1len = strlen(t1 + 1);
			for(int j = 1; j + s1len - 1 <= t1len; ++ j) {
				int flag = 1;
				FOR(k, 1, s1len) if(s1[i][k] != t1[j + k - 1]) { flag = 0; break; }
				if(flag == 0) continue;
				FOR(k, 1, j - 1) if(t1[k] != t2[k]) { flag = 0; break; }
				FOR(k, j + s1len, t1len) if(t1[k] != t2[k]) { flag = 0; break; }
				FOR(k, 1, s1len) if(s2[i][k] != t2[j + k - 1]) { flag = 0; break; }
				if(flag) cnt ++;
			}
		}
		printf("%lld\n", cnt);
	}
}

void subB() {
	FOR(i, 1, n) scanf("%s", s1[i] + 1), scanf("%s", s2[i] + 1);
	FOR(i, 1, n) {
		int l1 = strlen(s1[i] + 1), l2 = strlen(s2[i] + 1);
		FOR(j, 1, l1) if(s1[i][j] == 'b') p1[i] = j;
		FOR(j, 1, l2) if(s2[i][j] == 'b') p2[i] = j;
	}
	while(Q --) {
		scanf("%s", t1 + 1), scanf("%s", t2 + 1);
		if(strlen(t1 + 1) != strlen(t2 + 1)) { printf("0\n"); continue; } 
		int pt1 = 0, pt2 = 0;
		FOR(i, 1, strlen(t1 + 1)) if(t1[i] == 'b') pt1 = i;
		FOR(i, 1, strlen(t2 + 1)) if(t2[i] == 'b') pt2 = i;
		int tlen = strlen(t1 + 1);
		int t1pre = pt1 - 1, t1suf = tlen - pt1;
		int cnt = 0;
		FOR(i, 1, n) {
			int slen = strlen(s1[i] + 1);
			int s1pre = p1[i] - 1, s1suf = slen - p1[i];
			if(t1pre >= s1pre && t1suf >= s1suf) { // 可以塞进去 
				// 相同
				if(t1pre - s1pre + p2[i] == pt2) cnt ++;
			}
		}
		printf("%lld\n", cnt);
	}
}

signed main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	scanf("%lld%lld", &n, &Q);
	if(n <= 100 && Q <= 100) sub0();
	else subB();
	return 0;
}
