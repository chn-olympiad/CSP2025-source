#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define per(i, l, r) for(int i = l; i >= r; i--)
int read(){
	int res = 0, flg = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar()) if(c == '-') flg = -flg;
	for(; c >= '0' && c <= '9'; c = getchar()) res = (res << 3) + (res << 1) + c - '0';
	return res * flg;
}
void write(int x, char c = '\n'){
	if(x < 0) putchar('-'), x = -x;
	static int stk[35]; int top = 0;
	do { stk[top++] = x % 10; x /= 10; } while(x);
	while(top) { putchar(stk[--top] + '0'); }
	putchar(c);
}
const int N = 1e5 + 5;
int n;
namespace SUB11{
	const int N = 205;
	int dp[N / 2][N / 2][N / 2];
	int a[N][4];
	void solve(){
		rep(i, 1, n){
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read();
		}
		int ans = 0;
		rep(i, 0, n / 2){
			rep(j, 0, min(n / 2, n - i)){
				rep(k, 0, min(n / 2, n - i - j)){
					if(k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[i + j + k][3]);
					if(j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[i + j + k][2]);
					if(i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i + j + k][1]);
					
//					fprintf(stderr, "i: %d j: %d k: %d dp: %d\n", i, j, k, dp[i][j][k]);
					if(i + j + k == n){
						ans = max(ans, dp[i][j][k]);	
					}
				}
			}
		}
		rep(i, 0, n / 2){
			rep(j, 0, min(n / 2, n - i)){
				rep(k, 0, min(n / 2, n - i - j)){
					dp[i][j][k] = 0;
				}
			}
		}
		write(ans);
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
int a[N][4];
namespace SUB_B{
	int d[N];
	void solve(){
		int ans = 0;
		rep(i, 1, n){
			ans += a[i][1];
			d[i] = a[i][2] - a[i][1];
		}
		sort(d + 1, d + n + 1, greater<int>());
		rep(i, 1, n / 2){
			ans += d[i];
		}
		write(ans);
	}
}
namespace SUB_C{
	priority_queue<int> q1, q2, q3;
	void solve(){
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		ll ans = 0;
		rep(i, 1, n){
			int res = max(max(a[i][1], a[i][2]), a[i][3]);
			if(a[i][1] == res) q1.push(max(a[i][2] - a[i][1], a[i][3] - a[i][1]));
			if(a[i][2] == res) q2.push(max(a[i][1] - a[i][2], a[i][3] - a[i][2]));
			if(a[i][3] == res) q3.push(max(a[i][2] - a[i][3], a[i][1] - a[i][3]));
			ans += res;
		}
		if(q1.size() > n / 2){
			int tmp = q1.size();
			while(tmp > n / 2){
				ans += q1.top();
				cerr << q1.top() << '\n';
				q1.pop();
				tmp--;
			}
		}
		if(q2.size() > n / 2){
			int tmp = q2.size();
			while(tmp > n / 2){
				ans += q2.top();
				q2.pop();
				tmp--;
			}
		}
		if(q3.size() > n / 2){
			int tmp = q3.size();
			while(tmp > n / 2){
				ans += q3.top();
				q3.pop();
				tmp--;
			}
		}
		write(ans);
	}
}
/*

*/
void solve(){
	n = read();
	if(n <= 200) return SUB11::solve(), void();
	
	bool flg_B = 1;
	rep(i, 1, n){
		a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
		if(a[i][3]) flg_B = 0;
	}
	if(flg_B) return SUB_B::solve(), void();
	SUB_C::solve();
}
signed main(){
	#ifndef MY_JUDGE
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
	#endif
	
	#ifdef MY_JUDGE
//		freopen("club5.in", "r", stdin);
//		freopen("my.out", "w", stdout); 
	#endif
	int T = read();
	while(T--) solve();
	return 0;
}
