#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int N = 2e2+10;
int dp[N][N][N];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		ans = 0;
		rep(i,0,n){
			rep(j,0,n){
				rep(k,0,n){
					dp[i][j][k] = 0;
				}
			}
		}
//		memset(dp,0,sizeof dp);
		rep(i,1,n){
			int x,y,z;
			cin >> x >> y >> z;
			for(int a=n;a>=0;a--){
				for (int b=n;b>=0;b--){
					for (int c = n;c>=0;c--){
						if (a){
							dp[a][b][c] = max(dp[a][b][c],dp[a-1][b][c]+x);
						}
						if (b){
							dp[a][b][c] = max(dp[a][b][c],dp[a][b-1][c]+y);
						}
						if (c){
							dp[a][b][c] = max(dp[a][b][c],dp[a][b][c-1]+z);
						}
					}
				}
			}
			rep(a,0,n){
				rep(b,0,n){
					rep(c,0,n){
						if (a > n/2 || b > n/2 || c > n/2) continue;
						if (a + b + c != n) continue;
						ans = max(ans,dp[a][b][c]);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

