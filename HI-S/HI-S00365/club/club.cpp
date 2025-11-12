#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
int a[100005][5]; 
int dp[205][205][205];
void test()
{	
	int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            a[i][j]=0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int half = n / 2;
    for (int i = 1; i <= n; i++) {
        for (int c1 = 0; c1 <= half; c1++) {
            for (int c2 = 0; c2 <= half; c2++) {
            	dp[i][c1][c2]=0;
				}
			}
		}
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int c1 = 0; c1 <= half; c1++) {
            for (int c2 = 0; c2 <= half; c2++) {
                int c3 = i - 1 - c1 - c2;
                if (c3 < 0 || c3 > half) continue;
                if (dp[i-1][c1][c2] == -INF) continue;
                
                if (c1 + 1 <= half) {
                    dp[i][c1+1][c2] = max(dp[i][c1+1][c2], 
                                         dp[i-1][c1][c2] + a[i][1]);
                }
                
                if (c2 + 1 <= half) {
                    dp[i][c1][c2+1] = max(dp[i][c1][c2+1], 
                        dp[i-1][c1][c2] + a[i][2]);
                }
                if (c3 + 1 <= half) {
                    dp[i][c1][c2] = max(dp[i][c1][c2], 
                            dp[i-1][c1][c2] + a[i][3]);
                }
            }
        }
    }
    int ans = -INF;
    for (int c1 = 0; c1 <= half; c1++) {
        for (int c2 = 0; c2 <= half; c2++) {
            int c3 = n - c1 - c2;
            if (c3 >= 0 && c3 <= half) {
                ans = max(ans, dp[n][c1][c2]);
            }
        }
    }
    
    cout << ans << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) test();
	return 0;
}
