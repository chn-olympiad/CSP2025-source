#include<bits/stdc++.h>
#define ll long long
#define fast_running ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int N = 510;
const ll Mod = 998244353;
ll n, m, ans;
int a[N];
bool vis[N];
string d;
inline void dfs(int t, int kick, int use) {
	if (t == n + 1) {
		if (use >= m) ++ans;
		if (ans >= Mod) ans -= Mod;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			if (kick < a[i] && d[t - 1] == '1') dfs(t + 1, kick, use + 1);
			else dfs(t + 1, kick + 1, use);
			vis[i] = 0;
		}
	}
	return;
}
void subtask1() {
	dfs(1, 0, 0);
	cout << ans;
}
ll A(int x) {
	ll res = 1;
	for (int i = 1; i <= x; i++) res = (res * i) % Mod;
	return res;
}
void subtask2() {  // He was died...
	int kick = 0;
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == '1') {
			ll sum = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] > kick) ++sum;
 			}
 			sum = (sum * A(n - 1)) % Mod;
			ans = (ans + sum) % Mod;
		}else ++kick;
	}
	cout << ans;
	return;
}
void subtask3() {  // He was died, too...
	int can = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) ++can;
	}
	if (can < m) {
		cout << 0;
	}else cout << A(n);
	return;
}
int main() {
	fast_running;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 18) {
		subtask1();
	}else cout << 0;
	return 0;
}


/*
//  freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
#pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma #pragma
#define #define #define #define #define #define #define #define #define #define #define #define #define #define #define #define
//  freopen("emlpoy.in", "r", stdin);
//	freopen("emlpoy.out", "w", stdout);


Hello, I am a OIer that isn`t get lots of points in this problem.(1294410)
I want to get 200 pts so that I can atend NOIP, but I can`t.
I only can atend NOIP at senior high school.
emm...
See you next year if I won`t AFO.


And give this song to someone(wz):

Take my hand now
Stay close to me
Be my lover 
Won`t you let me go
Close your eyes now
And you will see
There is a rainbow
For you and me
*/
