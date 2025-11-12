#include <bits/stdc++.h>
#define space putchar(' ')
#define newline puts("")
#define int long long
using namespace std;

const int N = 100005;
int T, n, a[N][5], d[N], cnt1, cnt2, cnt3, ans;

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= 3; ++j){
				cin >> a[i][j];
			}
		}
		ans = cnt1 = cnt2 = cnt3 = 0;
		priority_queue <int> q1, q2, q3;
		for(int i = 1; i <= n; ++i){
			int t = max(max(a[i][1], a[i][2]), a[i][3]);
			if(t == a[i][1]){
				++cnt1;
				q1.push(max(a[i][2], a[i][3]) - t);
			}
			if(t == a[i][2]){
				++cnt2;
				q2.push(max(a[i][1], a[i][3]) - t);
			}
			if(t == a[i][3]){
				++cnt3;
				q3.push(max(a[i][1], a[i][2]) - t);
			}
			ans += t;
		}
		if(cnt1 * 2 > n){
			while(cnt1 * 2 > n){
				ans += q1.top();
				q1.pop();
				--cnt1;
			}
		}
		if(cnt2 * 2 > n){
			while(cnt2 * 2 > n){
				ans += q2.top();
				q2.pop();
				--cnt2;
			}
		}
		if(cnt3 * 2 > n){
			while(cnt3 * 2 > n){
				ans += q3.top();
				q3.pop();
				--cnt3;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
