#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 10;
int n, ans, sum[3], a[maxn][3], b[maxn], col[maxn];
int get(int i, int kind) {
	if(kind == 0) return max(a[i][1], a[i][2]);
	if(kind == 1) return max(a[i][0], a[i][2]);
	return max(a[i][0], a[i][1]);
}
struct T {
	int pos, val;
	bool operator < (const T & t) const {
		return val < t.val;
	}
};
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t --) {
		cin >> n; ans = 0; sum[0] = sum[1] = sum[2] = 0;
		for(int i = 1; i <= n; ++ i) {
			for(int j = 0; j < 3; ++ j) cin >> a[i][j];	
			b[i] = max({a[i][0], a[i][1], a[i][2]});
		}
		//cerr << "ok";
		for(int i = 1; i <= n; ++ i) {
			for(int j = 0; j < 3; ++ j) {
				if(a[i][j] == b[i]) {
					ans += a[i][j];
					col[i] = j;
					++ sum[j];
					break;
				}
			}
		}
		int kind;
		if(sum[0] > sum[1] && sum[0] > sum[2]) kind = 0;
		else if(sum[1] > sum[2]) kind = 1;
		else kind = 2;
		priority_queue <T> q;
		for(int i = 1; i <= n; ++ i) {
			if(col[i] == kind) q.push({i, get(i, kind) - b[i]});
			//cerr << "@@@" << col[i] << " " << kind << "\n";
		}
		//cerr << "###" << q.size() << "\n"; 
		while(sum[kind] > n / 2 && !q.empty()) {
			//cerr << "!!!" << q.size() << "\n";
			T t = q.top(); q.pop();
			ans += t.val; -- sum[kind];
		}
		cout << ans << "\n";
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
我要上洛谷迷惑行为大赏
永世传颂，不休独舞，神爱世人，芙门永存。
*/