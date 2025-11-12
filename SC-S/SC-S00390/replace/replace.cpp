#include <bits/stdc++.h>
using std::pair;
using std::map;
const int M = 5000005, N = 200005;
typedef unsigned long long ull;
typedef long long ll;
const ull P = 3113313113;
int s1[M], s2[M];
int n, q;
map < pair < ull, ull >, ll > flag;
//map < int, ll > flag2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		char t;
//		int id1 = 0, id2 = 0;
		ull thash1 = 0, tp = 1, thash2;
//		int id = 0;
		while((t = getchar()) < 'a') ;
		for(; t >= 'a'; t = getchar()) {
			thash1 = thash1 + tp * (t - 'a' + 1);
			tp *= P;
//			id++;
//			if(t == 'b') id1 = id;
		}
//		id = 0;
		thash2 = 0, tp = 1;
		while((t = getchar()) < 'a') ;
		for(; t >= 'a'; t = getchar()) {
			thash2 = thash2 + tp * (t - 'a' + 1);
			tp *= P;
//			id++;
//			if(t == 'b') id2 = id;
		}
//		flag2[id1 - id2]++;
//		printf("%llu %llu\n", hash1[i], hash2[i]);
		flag[{thash1, thash2}]++;
	}
	while(q--) {
		int len1 = 0, len2 = 0;
//		int id1 = 0, id2 = 0;
		char t;
		while((t = getchar()) < 'a') ;
		for(; t >= 'a'; t = getchar()) {
			s1[++len1] = t - 'a' + 1;
//			if(t == 'b') id1 = len1;
		}
		while((t = getchar()) < 'a') ;
		for(; t >= 'a'; t = getchar()) {
			s2[++len2] = t - 'a' + 1;
//			if(t == 'b') id2 = len2;
		}
		if(len1 != len2) {
			puts("0");
			continue;
		}
		int len = len1;
//		if(len <= 2005) {
			int r;
			for(r = len; r >= 1; r--) {
				if(s1[r] != s2[r]) {
					break;
				}
			}
			ll ans = 0;
			for(int i = 1; i <= len; i++) {
				if(s1[i - 1] != s2[i - 1] && i > 1) break;
				ull thash1 = 0, tp = 1, thash2 = 0;
				for(int j = i; j <= len; j++) {
					thash1 = thash1 + tp * s1[j];
					thash2 = thash2 + tp * s2[j];
					tp *= P;
//				printf("%d %d : %llu %llu\n", i, j, thash1, thash2);
					if(flag.count({thash1, thash2}) && j >= r) ans += flag[{thash1, thash2}];
				}
			}
			printf("%lld\n", ans);
//		} else {
//			printf("%lld\n", flag2[id1 - id2]);
//		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}