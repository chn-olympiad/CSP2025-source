#include <bits/stdc++.h>

#define mod 998244353
#define N ((int)5e3 + 10)

using namespace std;

int n, a[N];

inline void solve1(); //n <= 20
inline bool check_case2();
inline void solve2(); //max(a[i]) = 1

int main() {
#ifdef XYX
//	freopen("polygon3.in", "r", stdin);
//	freopen("polygon3.out", "w", stdout);
#else 
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	if(n <= 20) {
		solve1();
	}
	else if(check_case2()) {
		solve2();
	}
	
	return 0;
}

inline void solve1() {
#ifdef XYX
//	int ttt[20] = {0};
#endif
	
	int ans = 0;
	for(int k = 0;k < (1 << n);k++) {
		int cnt = 0;
		int mx = 0, sum = 0;
		for(int i = 0;i < n;i++) {
			if((k & (1 << i))) {
				++cnt;
				mx = max(mx, a[i + 1]);
				sum += a[i + 1];
			}
		}
		
		if(cnt < 3) continue;
		if(sum <= 2 * mx) continue;
		
#ifdef XYX
//		ttt[cnt]++;
//		cout << k << endl;
#endif
		ans = (ans + 1) % mod;
	}
#ifdef XYX
//	for(int i = 3;i <= n;i++) {
//		cout << ttt[i] << " ";
//	}
//	cout << endl;
#endif
	cout << ans;
}

int C[N][N];
inline void init_C() {
	C[0][0] = 1;
	C[1][0] = C[1][1] = 1; 
	for(int i = 2;i <= n;i++) {
		for(int j = 0;j <= i;j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
#ifdef XYX
	for(int i = 0;i <= n;i++) {
		for(int j = 0;j <= i;j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
#endif
}

inline bool check_case2() {
	int mx = 0;
	for(int i = 1;i <= n;i++) {
		mx = max(mx, a[i]);
	}
	return (mx == 1);
}
inline void solve2() {
	init_C();
	
	int ans = 0;
	for(int i = 3;i <= n;i++) {
		ans = (ans + C[n][i]) % mod;
	}
	cout << ans % mod;
} 