#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
//#define int long long
//#define int unsigned long long
using namespace std;
const int N = 1e6+10;
int T,n,vis[4],maxn,dp[N][4][2];
bool flag,flag2;
struct club {
	int x,y,z;
}a[N];
bool cmp(club a,club b) {return a.y > b.y;}
signed main() {
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x != 0 && a[i].z == 0) flag = true;
			if(a[i].z != 0) flag2 = true;
		}
		if(!flag) {
			sort(a+1,a+n+1,cmp);
			int ans = 0;
			for(int i = 1; i <= n/2; i++) {
				ans += a[i].y;
			}cout << ans << "\n";
			continue;
		}if(flag) {
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				ans += max(a[i].x,a[i].y);
			}cout << ans << "\n";
			continue;
		}if(1) {
			int ans1 = 0,ans2 = 0,ans3 = 0;
			dp[1][1][1] = a[1].x;dp[1][2][1] = a[1].y;dp[1][3][1] = a[1].z;
			for(int i = 2; i <= n; i++) {
				for(int j = 1; j <= 3; j++) {
						if(j == 1) {
							if(1) {
								dp[i][j][1] = max(dp[i-1][j+1][1],max(dp[i-1][j+2][1],dp[i-1][j][1]))+a[i].x;
								
							}dp[i][j][0] = max(dp[i-1][j+1][1],max(dp[i-1][j+2][1],dp[i-1][j][1]));
						}else if(j == 2) {
							if(1) {
								dp[i][j][1] = max(dp[i-1][j-1][1],max(dp[i-1][j+1][1],dp[i-1][j][1]))+a[i].y;
								
							}dp[i][j][0] = max(dp[i-1][j-1][1],max(dp[i-1][j+1][1],dp[i-1][j][1]));
						}else {
							if(1) {
								dp[i][j][1] = max(dp[i-1][j-1][1],max(dp[i-1][j-2][1],dp[i-1][j][1]))+a[i].z;
								
							}dp[i][j][0] = max(dp[i-1][j-1][1],max(dp[i-1][j-2][1],dp[i-1][j][1]));
						}
						maxn = max(maxn,max(dp[i][j][1],dp[i][j][0]));
					}
				}
				cout << maxn << "\n";
			}
		}
	return 0; 
}
