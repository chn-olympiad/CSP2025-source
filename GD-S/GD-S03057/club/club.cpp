#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 100010

struct node {
	int a, b, c;
}p[N];

int t, n;
int SX;

int d[N];
int mxk[N];
int mx = -1;
int st;
void dfs(int k, int cnta, int cntb, int cntc, int ans) {
	if(cnta > SX || cntb > SX || cntc > SX) {
		return;
	}
	if(k == n + 1) {
		mx = max(mx, ans);
		return;
	}
	d[k] = 1;
	dfs(k + 1, cnta + 1, cntb, cntc, ans + p[k].a);
	
	d[k] = 2;
	dfs(k + 1, cnta, cntb + 1, cntc, ans + p[k].b);
	
	d[k] = 3;
	dfs(k + 1, cnta, cntb, cntc + 1, ans + p[k].c);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	st = clock();
	cin >> t;
	while(t--) {
		cin >> n;	
		bool At = true, Bt = true;
		for(int i = 1;i <= n;i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			if(p[i].b != 0 || p[i].c != 0) {
				At = false;
			}
			if(p[i].c != 0) {
				Bt = false;
			}
		}
		mx = -1;
		SX = n / 2;
		
		if(n > 30 && At == true) {
			vector<int> ans;
			for(int i = 1;i <= n;i++) {
				ans.push_back(p[i].a);
			}
			sort(ans.begin(), ans.end(), greater<int>() );
			int sum = 0;
			for(int i = 0;i < SX;i++) {
				sum += ans[i];
			}
			cout << sum << "\n";
		} else if(n > 30 && Bt == true) {
			int sum = 0;
			for(int i = 1;i <= n;i++) {
				sum += p[i].a;
			}
			vector<int> ans;
			for(int i = 1;i <= n;i++) {
				ans.push_back(p[i].b - p[i].a);
			}
			sort(ans.begin(), ans.end(), greater<int>() );
			for(int i = 0;i < SX;i++) {
				sum += ans[i];
			}
			cout << sum << "\n";
		} else {
			dfs(1, 0, 0, 0, 0);
			cout << mx << "\n";
		}
	}
	return 0;
} 
