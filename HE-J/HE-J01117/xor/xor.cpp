#include <bits/stdc++.h> // 30 fen
using namespace std;
const int N = 5e5 + 5;
int a[N], f[N][2], cnt[2];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, maxx = 0; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	a[n + 1] = -1;
	if (maxx <= 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) ans++;
			else if (i + 1 <= n && a[i + 1] != k) {
				ans ++;
				i++;
			}
		}
		cout << ans;
		return 0;
	}
	
	vector <int> v[2][1005];
	int ans = 0, cntv[2] = {0, 1};
	for (int i = 1; i <= n; i++) {
		if (a[i] != k) {
			v[1][cntv[1]].push_back(a[i]);
		}
		else {
			if (v[1][cntv[1]].size() < 2) 
				v[1][cntv[1]].clear();
			else cntv[1] ++;
			ans++;
		}
	}
	for (int K = 2; K <= n; K++) {
		int ks = K & 1;
		for (int i = 1; i <= cnt[ks]; i++) v[ks][i].clear();
		cnt[ks] = 1;
		if (cntv[!ks] == 1) break;
		for (int i = 1; i <= cntv[!ks]; i++) {
			#define vlast v[!ks][i]
			int xors = 0;
			for (int j = 0; j < vlast.size(); j++) {
				
				for (int g = 0; g < k - 1; g++) {
					xors ^= vlast[g];
					v[ks][cntv[ks]].push_back(vlast[g]);
				}
				for (int g = k - 1; g < vlast.size(); g++) {
					xors ^= vlast[g];
					if (xors != k) {
						v[ks][cntv[ks]].push_back(vlast[g]);
					}else {
						xors = 0;
						if (v[ks][cntv[ks]].size() < K) v[ks][cntv[ks]].clear();
						else cntv[ks]++;
						ans++;
						//cout << K << " " << g << "\n";
					}
				}
				
				
			}
		}
	}
	cout << ans;
	
	return 0;
}

