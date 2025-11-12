#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int t;
int n, a[N][4];

bool ck(int x, int y, int z, int s){
	int d[4] = {};
	d[x]+1;
	d[y]+1;
	d[z]+1; 
	d[s]+1;
	cout << d[1] <<' '<< d[2] <<' '<< d[3]  << endl;
	if(d[3] <= 2 && d[2] <= 2 && d[1] <= 2){
		return 1;
	}else return 0;
}

int main (){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int ans = -1;
		memset(a, 0, sizeof a);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(n == 2){
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++ ) {
					if(i != j){
						ans = max(ans, a[1][i]+a[2][j]);
					}
				}
			} 
		}
		if(n == 3){
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++ ) {
					for(int k = 1; k <= 3; k++) {
						if(i != j && i != k && j != k){
							ans = max(ans, a[1][i]+a[2][j]+a[3][k]);
						}
					}
				}
			} 
		}
		if(n == 4){
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++ ) {
					for(int k = 1; k <= 3; k++) {
						for (int m = 1; m <= 3; m++) {
							if(ck(i, j, k ,m)){
								ans = max(ans, a[1][i]+a[2][j]+a[3][k]+a[4][m]);
							}	
						}
					}
				}
			} 
		}
		cout << ans << endl;
	}
	return 0;
} 
