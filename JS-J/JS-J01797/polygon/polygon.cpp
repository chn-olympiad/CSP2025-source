#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5000;
const int mod = 998244353;
int n, k, dp[N + 5];
int ans;
int a[N + 5];
int sum[N + 5];
int ssum[N + 5];
signed main(){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int flag = 1;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		if (a[i] != 1) flag = 0;
	}
	if (flag == 1){
		for (int i = 3; i <= n; ++ i){
			int ops = 1;
			for (int j = 1; j <= i; ++ j){
				ops = (ops * j) % mod;
			}
			int pp = n;
			int m = n - 1;
			int t = 1;
			while (t != i){
				pp = pp * m % mod;
				m --;
				t ++;
			}
			ans = (ans + pp / ops) % mod;
		}	
		cout << ans << endl;
	}
	
	else if (n <= 3){
		sort (a + 1, a + 1 + n);
		if (a[1] + a[2] > a[3]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	
	else if (n <= 10){
		sort (a + 1, a + 1 + n);
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					if (a[a0] + a[a1] > a[a2]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						if (a[a0] + a[a1] + a[a2] > a[a3]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						for (int a4 = a3 + 1; a4 <= n; ++ a4)
							if (a[a0] + a[a1] + a[a2] + a[a3] > a[a4]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						for (int a4 = a3 + 1; a4 <= n; ++ a4)
							for (int a5 = a4 + 1; a5 <= n; ++ a5)
								if (a[a0] + a[a1] + a[a2] + a[a3] + a[a4] > a[a5]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						for (int a4 = a3 + 1; a4 <= n; ++ a4)
							for (int a5 = a4 + 1; a5 <= n; ++ a5)
								for (int a6 = a5 + 1; a6 <= n; ++ a6)
									if (a[a0] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] > a[a6]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						for (int a4 = a3 + 1; a4 <= n; ++ a4)
							for (int a5 = a4 + 1; a5 <= n; ++ a5)
								for (int a6 = a5 + 1; a6 <= n; ++ a6)
									for (int a7 = a6 + 1; a7 <= n; ++ a7)
										if (a[a0] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] > a[a7]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						for (int a4 = a3 + 1; a4 <= n; ++ a4)
							for (int a5 = a4 + 1; a5 <= n; ++ a5)
								for (int a6 = a5 + 1; a6 <= n; ++ a6)
									for (int a7 = a6 + 1; a7 <= n; ++ a7)
										for (int a8 = a7 + 1; a8 <= n; ++ a8)
											if (a[a0] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] > a[a8]) ans ++;
		for (int a0 = 1; a0 <= n; ++ a0)
			for (int a1 = a0 + 1; a1 <= n; ++ a1)
				for (int a2 = a1 + 1; a2 <= n; ++ a2)
					for (int a3 = a2 + 1; a3 <= n; ++ a3)
						for (int a4 = a3 + 1; a4 <= n; ++ a4)
							for (int a5 = a4 + 1; a5 <= n; ++ a5)
								for (int a6 = a5 + 1; a6 <= n; ++ a6)
									for (int a7 = a6 + 1; a7 <= n; ++ a7)
										for (int a8 = a7 + 1; a8 <= n; ++ a8)
											for (int a9 = a8 + 1; a9 <= n; ++ a9)
												if (a[a0] + a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] > a[a9]) ans ++;
		cout << ans << endl;
	}
	return 0;
}

/*
 5
 1 2 3 4 5
 
 
 5
 2 2 3 8 10
 
 
 
*/
 /*
  10
  1 1 1 1 1  1 1 1 1 1
  */
 
