#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, Q = 3628810;
struct node{ int a, b, c; } p[N];
int dp[210][3][110];
bool cmp(node A, node B) {
	return max(max(A.a, A.b), A.c) > max(max(B.a, B.b), B.c);
}
bool cmp_b(node A, node B) {
	return abs(A.a - A.b) > abs(B.a - B.b);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t --) {
		long long ans = 0;
		memset(dp, 0, sizeof(dp));
		int n; cin >> n;
		bool f_A = 1, f_B = 1;
		int cnt[5] = {0, 0, 0, 0, 0};
		for(int i = 1; i <= n; i ++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			if(p[i].b) f_A = 0;
			if(p[i].c) f_B = f_A = 0;
		}
		if(f_A) {
			sort(p + 1, p + 1 + n, cmp);
			for(int i = 1; i <= n / 2; i ++) {
				ans += p[i].a;
			}
			cout << ans << '\n';
		} else if(f_B)	{
			sort(p + 1, p + 1 + n, cmp_b);
			bool fa = 1, fb = 1;
			for(int i = 1; i <= n; i ++) {
				if(p[i].a > p[i].b && fa) {
					++ cnt[1];
					ans += p[i].a;
					if(cnt[1] == n / 2) fa = 0;
				} 
				if(p[i].b > p[i].a && fb) {
					++ cnt[2];
					ans += p[i].b;
					if(cnt[2] == n / 2) fb = 0;
				}
			}
			cout << ans << '\n';
		} else {
			sort(p + 1, p + 1 + n, cmp);
			long long ans = 0;
			for(int i = 1; i <= n; i ++) {
				int id = 0;
				if(p[i].a > p[i].b && p[i].a > p[i].c) {
					id = 1;
					ans += p[i].a;
				} 
				if(p[i].b > p[i].a && p[i].b > p[i].c) {
					id = 2;
					ans += p[i].b;
				}
				if(p[i].c > p[i].a && p[i].c > p[i].b){
					id = 3;
					ans += p[i].c;
				}
				if(!id) {
					if(p[i].a == p[i].b && p[i].a > p[i].c) {
						if(cnt[1] < cnt[2]) {
							id = 1; 
							ans += p[i].a;
						} else {
							id = 2;
							ans += p[i].b;
						}
					}
					if(p[i].a == p[i].c && p[i].a > p[i].b) {
						if(cnt[1] < cnt[3]) {
							id = 1;
							ans += p[i].a;
						} else {
							id = 3;
							ans += p[i].c;
						}
					}
					if(p[i].b == p[i].c && p[i].b > p[i].a) {
						if(cnt[2] < cnt[3]) {
							id = 2;
							ans += p[i].b;
						} else {
							id = 3;
							ans += p[i].c;
						}
					}
				}
				++ cnt[id];
				if(cnt[id] == n / 2) {
					for(int j = i + 1; j <= n; j ++) {
						if(id == 1) p[j].a = 0;
						else if(id == 2) p[j].b = 0;
						else p[j].c = 0;
					}
					sort(p + 1, p + 1 + n, cmp);
				} 
			}
			cout << ans << '\n';
		}
	}
	return 0;
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
