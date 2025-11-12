#include <bits/stdc++.h>
using namespace std;
struct pos {
	int x, y;
};
int t, n, a[100005][5], cnts[5], ans;
pos getmax(){
	int maxn = 0;
	pos maxpos;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=3; j++){
			if (a[i][j] > maxn){
				maxn = a[i][j];
				maxpos.x = i;
				maxpos.y = j;
			}
		}
	}
	return maxpos;
}
void init(){
	for (int i=1; i<=3; i++){
		cnts[i] = 0;
	}
	ans = 0;
}
void run(){
	init();
	cin >> n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=3; j++){
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=3; j++){
			if (cnts[j] >= n/2){
				for (int k=1; k<=n; k++){
					a[k][j] = -1;
				}
			}
		}
		pos maxpos = getmax();
		ans += a[maxpos.x][maxpos.y];
		cnts[maxpos.y]++;
		for (int j=1; j<=3; j++){
			a[maxpos.x][j] = -1;
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i=1; i<=t; i++) run();
	return 0;
}
