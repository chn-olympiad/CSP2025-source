#include <bits/stdc++.h>
#define ll long long
#define fo(i,j) for (int i = 0; i < j; i ++)
using namespace std;

struct Node {
	int x, y, z;
};

bool cmp(Node a, Node b) {
	return a.x > b.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _; cin >> _;
	while (_ --) {
		int n; cin >> n;
		vector<Node> a(n);
		bool x_A = 1, x_B = 1;
		for (auto &[x, y, z] : a) {
			cin >> x >> y >> z;
			if (y != 0 || z != 0)
			   x_A = 0;
            if (z != 0)
               x_B = 0;
		}
		if (x_A) {
			sort(a.begin(), a.end(), cmp);
			ll sum = 0;
			fo (i, n / 2)
				sum += a[i].x;
			cout << sum << endl;
			continue;
		}/*
		int b[n];
		set<pair<int, int>> c[3];
		fo (i, n) {
		    bool h = a[i].x > a[i].y, g = a[i].x > a[i].z, k = a[i].y > a[i].z;
	        b[i] = (h && g ? 1 : (k && !h ? 2 : 3));
	        c[b[i]].insert({max(a[i].x, max(a[i].y, a[i].z)), i});
        }
        while (1) {
 		    int is_c[3] = {};
			fo (i, n) is_c[b[i]] ++;
 		    if (is_c[0] <= n / 2 && is_c[1] <= n / 2 && is_c[2] <= n / 2)
 		   	    break;
  	        int cnt = 0;
  	        for (auto &[x, y] : c[0]) {
  	        	if (cnt >= is_c[0] - n / 2) break;
  	        	cnt ++;
  	        }
	 	}
	 	ll ans = 0;
	 	fo (i, n) {
		 	switch(b[i]) {
				case 0:
					ans += a[i].x;
				case 1:
					ans += a[i].y;
				case 2:
					ans += a[i].z;
			}
		}
	 	cout << ans;
		continue;*/
		if (1LL * 27 * n * n * n <= 200000000) {
			ll ans = 0;
			fo(ix, n) fo(jx, n) fo(zx, n)
			fo(iix, 3) fo(jjx, 3) fo(zzx, 3) {
				if (ix == jx || jx == zx || ix == zx)
				   continue;
				ll sum = 0;
				switch(iix) {
					case 0: sum += a[ix].x;
					case 1: sum += a[ix].y;
					case 2: sum += a[ix].z;
				}
				switch(jjx) {
					case 0: sum += a[jx].x;
					case 1: sum += a[jx].y;
					case 2: sum += a[jx].z;
				}
				switch(zzx) {
					case 0: sum += a[zx].x;
					case 1: sum += a[zx].y;
					case 2: sum += a[zx].z;
				}
				ans = max(ans, sum);
			}
			cout << ans << endl;
			continue;
		}
		ll dp[n][3] = {};/*
		map<pair<int, int>, int> b[3];
		for (int i = 0; i < n; i ++) {
			ll x = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			if (i = 0) x = 0;
			dp[i][0] = dp[i][1] = dp[i][2] = x;
			if (i < n / 2) {
				dp[i][0] += a[i].x;
				dp[i][1] += a[i].y;
				dp[i][2] += a[i].z;
				b[0][dp[i][0], i] ++;
				b[1][dp[i][1], i] ++;
				b[2][dp[i][2], i] ++;
			}
			else {
				int na, nb, nc, nai, nbi, nci;
				for (auto &[x, y] : b[0]) {
					na = x, nai = y;
					break;
				}
				for (auto &[x, y] : b[1]) {
					nb = x, nbi = y;
					break;
				}
				for (auto &[x, y] : b[2]) {
					nc = x, nci = y;
					break;
				}
				if (na < a[i].x) {
					dp[i][0] += a[i].x - na;
				}
			}
		}*/
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
