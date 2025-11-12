#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int a[100010][10];
int d[10][10010];
int main(){
	freopen("club.in" , "r" , stdin); 
	freopen("club.out" , "w" , stdout);
	cin >> t;
	for(int ert = 1;ert <= t;ert ++){
		cin >> n;
		for(int i = 1;i <= n;i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for(int i = 1;i <= n;i ++){
			int ma = -1;
			for(int j = 1;j <= 3;j ++){
				ma = max(ma , a[i][j]);
			}
			for(int j = 1;j <= 3;j ++){
				if(a[i][j] == ma){
					ans += ma;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
