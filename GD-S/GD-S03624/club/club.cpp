#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long T, n, ans;
int a[N], b[N], c[N], d[N], flag[N];
int f[205][205][205];
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	for(cin >> T; T --> 0;){
		cin >> n; ans = 0;
		for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i];
		if(n <= 200){
			memset(f, 0, sizeof(f));
			for(int i=1; i<=n; i++){
				for(int j=0; j<=min(i+0ll, n/2); j++){
					for(int k=0; k<=min(i-j+0ll, n/2); k++){
						if(j) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + a[i]);
						if(k) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + b[i]);
						if(i - k - j) f[i][j][k] = max(f[i][j][k], f[i-1][j][k] + c[i]);
	//					cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
					}
				}
			}
			for(int i=0; i<=n/2; i++){
				for(int j=n/2-i; j<=n/2; j++){
	//				if(f[n][i][j] >= ans) cout << "qwq: " << i << ' ' << j << ' ' << f[n][i][j] << "\n";
					ans = max(ans, f[n][i][j] + 0ll);
				}
			}
			cout << ans << "\n";
		}
		else{
			priority_queue<pair<int, int>> q1, q2;
			for(int i=1; i<=n/2; i++){
				ans += a[i], q1.push({b[i] - a[i], i}), flag[i] = 1;
			}
			for(int i=n/2+1; i<=n; i++){
				ans += b[i], q2.push({a[i] - b[i], i}), flag[i] = 2;
			}
			while(1){
				auto [x, i] = q1.top();
				auto [y, j] = q2.top();
				if(x + y < 0) break;
				q1.pop(), q2.pop();
				q1.push({-y, j}), q2.push({-x, i});
				flag[i] = 2, flag[j] = 1;
				ans += x + y;
			}
			for(int i=1; i<=n; i++){
				if(flag[i] == 1) d[i] = c[i] - a[i];
				if(flag[i] == 2) d[i] = c[i] - b[i];
			}
			sort(d + 1, d + 1 + n, greater<int>());
			for(int i=1; i<=n/2; i++) if(d[i] > 0) ans += d[i];
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

What should I do ?????
*/
