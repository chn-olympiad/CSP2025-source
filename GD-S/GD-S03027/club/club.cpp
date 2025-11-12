#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int T;
int n, a[N][4], b[N], c[N], s[4], ans, maxx, flag;
void dfs(int t) {
	if(t == n + 1) {
		maxx = max(maxx, ans);
		return ;
	}
	else {
		for(int i = 1; i <= 3; i++) {
			if(s[i] < n / 2) {
				s[i]++;
				ans += a[t][i];
				dfs(t + 1);
				s[i]--;
				ans -= a[t][i];
			}
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		maxx = ans = 0;
		flag = 1;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i] = a[i][1];
			c[i] = a[i][2];
			if(a[i][3] != 0) flag = 0;
		}
		if(flag == 1) {
			sort(b + 1, b + n + 1);
			sort(c + 1, c + n + 1);
			for(int i = n; i >= n / 2 + 1; i--) { 
				ans += b[i];
				ans += c[i];
			}
			cout << ans << endl;
		}
		else {
			dfs(1);
			cout << maxx << endl;
		}
	}
	return 0;
}
