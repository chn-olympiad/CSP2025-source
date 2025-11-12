#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
const int mod = 998244353;
int c(int n, int m) {
	int mul = 1;
	for(int i = 0; i < m; i++) mul = mul % mod * (n - i) % mod;
	return mul % mod;
}
int qp(int n) {
	int ans = 0;
	for(int i = 0; i <= n; i++) ans = ans % mod + c(n, i);
	return ans % mod;
}
int n, m;
signed main() {
	//freopen("employ.in", "w", stdin);
    //freopen("employ.out", "r", stdout);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    printf("%d", qp(n));
    return 0;
}
/*
 CCCCCCC   SSSSSS   PPPPPPP          SSSSSS
C         S         P      P        S
C         S         P      P        S
C          SSSSSS   PPPPPPP   ----   SSSSSS
C                S  P                      S
C                S  P                      S
 CCCCCCC   SSSSSS   P                SSSSSS
*/

// Everything is gone......I only have 10pts......
