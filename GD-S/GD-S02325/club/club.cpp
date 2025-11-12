#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int _N = N + 5;
int a[_N][3], maxn[_N];
int bmc1, bmc2, bmc3;
int bm1[_N], bm2[_N], bm3[_N];
int calri(int i) {
	int mi = 0, pi;
	for(int j = 0; j <= 2; j++) {
		if(a[i][j] == maxn[i]) pi = j;
	}
	for(int j = 0; j <= 2; j++) {
		if(pi != j) mi = max(mi, a[i][j]);
	}
	int ri = maxn[i] - mi;
	return ri;
}
bool cmp(int a, int b) {
	return calri(a) < calri(b);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		bmc1 = 0; bmc2 = 0; bmc3 = 0;
		memset(maxn, 0, sizeof(maxn));
		memset(bm1, 0, sizeof(bm1));
		memset(bm2, 0, sizeof(bm2));
		memset(bm3, 0, sizeof(bm3));
		int n; cin >> n; int h = n / 2;
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			maxn[i] = max(a[i][0], max(a[i][1], a[i][2]));
			for(int j = 0; j <= 2; j++) {
				if(maxn[i] == a[i][j]) {
					if(j == 0) {bmc1++; bm1[bmc1] = i;}
					if(j == 1) {bmc2++; bm2[bmc2] = i;}
					if(j == 2) {bmc3++; bm3[bmc3] = i;}
					ans += maxn[i];
					break;
				}
			}
		}
		sort(bm1 + 1, bm1 + bmc1 + 1, cmp); 
		sort(bm2 + 1, bm2 + bmc2 + 1, cmp); 
		sort(bm3 + 1, bm3 + bmc3 + 1, cmp); 
		/*cout << endl << "TEST CASE T-" << T << endl;
		cout << "L1: "; for(int i = 1; i <= bmc1; i++) cout << bm1[i] << " "; cout << endl;
		cout << "L2: "; for(int i = 1; i <= bmc2; i++) cout << bm2[i] << " "; cout << endl;
		cout << "L3: "; for(int i = 1; i <= bmc3; i++) cout << bm3[i] << " "; cout << endl;
		cout << "S1A: " << ans << endl;
		for(int i = 1; i <= n; i++) {
			cout << "P" << i << ": ";
			cout << calri(i) << endl;
		}*/
		if(bmc1 > h) for(int i = 1; i <= bmc1 - h; i++) ans -= calri(bm1[i]);	
		if(bmc2 > h) for(int i = 1; i <= bmc2 - h; i++) ans -= calri(bm2[i]);
		if(bmc3 > h) for(int i = 1; i <= bmc3 - h; i++) ans -= calri(bm3[i]);
		cout << ans << endl;
	}
	return 0;
} 
