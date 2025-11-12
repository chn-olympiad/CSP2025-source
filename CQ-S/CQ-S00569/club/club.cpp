#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int maxn = 1e5 + 1 ;
int w[maxn][4] ;
int n ;
ll ans ;
struct note {
	int id, val, c ;
	bool operator < (const note &x) { return c < x.c ; }
};
std::vector<note> A, B, C ;

void Solve() {
	A.clear(), B.clear(), C.clear() ;
	scanf("%d", &n) ; ans = 0 ;
	for(int i=1 ; i<=n ; i++) {
		for(int j=1 ; j<=3 ; j++) scanf("%d", &w[i][j]) ;
		ans += std::max({w[i][1], w[i][2], w[i][3]}) ;
		if(w[i][1] > w[i][2]) {
			if(w[i][1] > w[i][3]) {
				if(w[i][2] > w[i][3]) A.push_back({i, w[i][1], w[i][1] - w[i][2]}) ;
				else A.push_back({i, w[i][1], w[i][1] - w[i][3]}) ;
			}
			else C.push_back({i, w[i][3], w[i][3] - w[i][1]}) ;
		}
		else {
			if(w[i][2] > w[i][3]) {
				if(w[i][1] > w[i][3]) B.push_back({i, w[i][2], w[i][2] - w[i][1]}) ;
				else B.push_back({i, w[i][2], w[i][2] - w[i][3]}) ;
			}
			else C.push_back({i, w[i][3], w[i][3] - w[i][2]}) ;
		}
	}
//	printf("%lld\n", ans) ;
	if(A.size() > (n >> 1)) {
//		puts("A") ;
		std::sort(A.begin(), A.end()) ;
		for(int k=1 ; k<=A.size()-(n>>1) ; k++) ans -= A[k - 1].c ;
	}
	if(B.size() > (n >> 1)) {
//		puts("B") ;
		std::sort(B.begin(), B.end()) ;
		for(int k=1 ; k<=B.size()-(n>>1) ; k++) ans -= B[k - 1].c ;
	}
	if(C.size() > (n >> 1)) {
//		puts("C") ;
		std::sort(C.begin(), C.end()) ;
//		for(auto x:C) {
//			printf("%d %d\n", x.id, x.c) ;
//		}
//		putchar('\n') ;
		for(int k=1 ; k<=C.size()-(n>>1) ; k++) ans -= C[k - 1].c ;
	}
	printf("%lld\n", ans) ;
	return ;
}

signed main() {
	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	int _t ;
	scanf("%d", &_t) ;
	while(_t --) Solve() ;
	return 0 ;
}
