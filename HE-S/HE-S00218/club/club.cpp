#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
inline void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for ( ; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = -f;
		}
	}
	for ( ; isdigit(c); c = getchar()) {
		x = (x << 3) + (x << 1) + (c & 15);
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if (x < 0) {
		x = -x;
		putchar ('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar ((x % 10) | 48);
}
const int N = 1e5 + 50; 
int t, n, a[N][5], cnt[5], maxn[N], dp[N][5];
int b[N];
struct node {
	int dis, x, y, ma;
	inline bool operator < (node c) const {
		if (dis != c.dis) return dis < c.dis;
		else return ma > c.ma;
	}
};
priority_queue<node> q;
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	read(t);
	while (t --) {
		read(n);
		memset(dp, 0, sizeof dp);
		memset(maxn, 0, sizeof maxn);
		memset(cnt, 0, sizeof cnt);
		while (!q.empty()) {
			q.pop();
		}
		bool f = false;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				read(a[i][j]);
				maxn[i] = max(maxn[i], a[i][j]);
			}
		}	
		for (int i = 1; i <= n; i ++) {
			if (a[i][2] != 0 || a[i][3] != 0) {
				f = true;
			}
			for (int j = 1; j <= 3; j ++) {
				q.push((node){a[i][j], i, j, maxn[i]});
			}
		}	
		if (!f) {
			for (int i = 1; i <= n ; i ++){
				b[i]=a[i][1];
			}
			sort(b + 1, b + 1 + n);
			int sum = 0;
			for (int i = n; i >= n / 2; i --) {
				sum += b[i];
			}
			cout << sum;
			return 0;
		}
		for (int i = 1; i <= n; i ++) {
			int ma = 0, w = 0;
			for (int j = 1; j <= 3; j ++) {
				if (ma < a[i][j]) {
					ma = a[i][j];
					w = j;
				}
				if (j == 1) {
					dp[i][j] = max(a[i][j], dp[i - 1][j]);
				} else {
					if (j == 3) cnt[w] ++; 
					dp[i][j] = ma + dp[i - 1][j];
				}
			}
 		}
 		for (int i = 1; i <= 3; i ++) {
 			if (cnt[i] > n / 2) {
 				while (!q.empty() && cnt[i] > n / 2) {
 					int dis = q.top().dis, x = q.top().x, y = q.top().y;
 					if (cnt[y] < n / 2) {
 						dp[n][3] -= maxn[x] - dis;
 						cnt[i] --;
 						cnt[y] ++;
					}
					q.pop();
				}
			}
		}
		cout << dp[n][3] << '\n';
	}
	return 0;
}
