#include <bits/stdc++.h>
using namespace std;
int t, n, a[100000+10][3];
int bg[100000+10], rn[100000+10], rndoi[100000+10];
int mgcdo(int stu) {
	int maxlove = max(a[stu][0], max(a[stu][1], a[stu][2]) );
	if(maxlove == a[stu][0]) return 0;
	if(maxlove == a[stu][1]) return 1;
	if(maxlove == a[stu][2]) return 2;
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int gf[3] = {0, 0, 0};
		cin >> n;
		for(int j = 1; j <= n; j++) {
			cin >> a[j][0] >> a[j][1] >> a[j][2];
			bg[j] = mgcdo(j); gf[ bg[j] ]++; 
			int z = mgcdo(j);
			rn[j] = a[j][z] - max(a[j][(z+1)%3], a[j][(z+2)%3]);
		}
		
		long long ans = 0; for(int j = 1; j <= n; j++) ans += 1LL * a[j][ bg[j] ];
		if(gf[0] > n/2 || gf[1] > n/2 || gf[2] > n/2) {
			int overg = 3; int ogtick = 0;
			if(gf[0] > n/2) overg = 0; if(gf[1] > n/2) overg = 1; if(gf[2] > n/2) overg = 2;
			
			for(int i = 1; i <= n; i++) if(bg[i] == overg) {ogtick++, rndoi[ogtick] = rn[i];}
			sort(rndoi+1, rndoi+ogtick+1);
			int overgf = gf[overg]; int rnsum = 1;
			while(overgf > n/2) {
				//cout << "qwq#" << rndoi[rnsum] << " ";
				ans -= rndoi[rnsum] * 1LL; rnsum++, overgf--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
