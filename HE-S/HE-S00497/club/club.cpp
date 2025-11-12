#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n , ans , num;
int a[N][3] , t[5] , p[N] , s[N];

/*

*/

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --) {
		cin >> n;
		for(int i = 1;i <= n;i ++)
			for(int j = 0;j < 3;j ++) cin >> a[i][j];
		t[0] = t[1] = t[2] = ans = num = 0;//
		for(int i = 1;i <= n;i ++) {
			int mx = max({a[i][0] , a[i][1] , a[i][2]});
			ans += mx;
			for(int j = 0;j < 3;j ++)
				if(a[i][j] == mx) {
					p[i] = j;
					t[j] ++; break;
				}
		}
		for(int op = 0;op < 3;op ++) {
			if(t[op] > n / 2) {
				for(int j = 1;j <= n;j ++) {
					if(p[j] == op) {
						int mx = 0;
						for(int k = 0;k < 3;k ++) if((p[j] != k) && a[j][k] > mx) mx = a[j][k];
						s[++ num] = a[j][p[j]] - mx;
					}
				}
				sort(s + 1 , s + num + 1);
				for(int i = 1;i <= num - n / 2;i ++) ans -= s[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
