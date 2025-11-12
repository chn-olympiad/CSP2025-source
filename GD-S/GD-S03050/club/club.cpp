#include <bits/stdc++.h>
using namespace std;

int t, n, d[3][100001], ans=0;
	
bool com(int a, int b) {
	return d[0][a]-d[1][a] > d[0][b]-d[1][b];
}
	
int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	for (int i=0; i<t; i++) {
		vector <int> v;
		cin >> n;
		ans=0;
		for (int j=0; j<n; j++) {
			cin >> d[0][j] >> d[1][j] >> d[2][j];
			v.push_back(j);
		}
		//输入
		 
		if (n==2) {
			for (int j=0; j<3; j++) {
				for (int k=0; k<3; k++) {
					if (k != j) {
						ans = max(ans, d[j][0]+d[k][1]);
					}
				}
			}
		}
		//特殊情况
		 	

		else {
			sort (v.begin(), v.end(), com);
			for (int j=0; j<n/2; j++) {
				ans+=d[0][v[j]];
			}
			for (int j=n/2; j<n; j++) {
				ans+=d[1][v[j]];
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
