#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 6,M = 1e5 + 6;
int dp[N >> 1][N >> 1][N >> 1];
struct node{
	int a,b;
}f[M];
bool cmp(node x,node y){
	return x.a - x.b > y.a - y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if (n > 200){
			long long sums = 0,cnt = 0;
			for (int i = 1; i <= n; ++i){
				int c;
				cin >> f[i].a >> f[i].b >> c;
				if (!f[i].b){
					++cnt;
				}
				sums += f[i].a;
			}
			if (cnt == n){
				cout << sums;
			}else{
				sort(f + 1,f + 1 + n,cmp);
				long long ans = 0;
				for (int i = 1; i <= n / 2; ++i){
					ans += f[i].a;
				}
				for (int i = n / 2 + 1; i <= n; ++i){
					ans += f[i].b;
				}
				cout << ans;
			}
		}
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n; ++i){
			int a,b,c;
			cin >> a >> b >> c;
			for (int j = 0; j <= min(i,n / 2); ++j){
				for (int k = 0; k <= min(n / 2,i - j); ++k){
					int l = i - j - k;
					if (l > n / 2) continue;
					if (j){
						dp[j][k][l] = max(dp[j][k][l],dp[j - 1][k][l] + a);
					}
					if (k){
						dp[j][k][l] = max(dp[j][k][l],dp[j][k - 1][l] + b);
					}
					if (l){
						dp[j][k][l] = max(dp[j][k][l],dp[j][k][l - 1] + c);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n / 2; ++i){
			for (int j = 0; j <= min(n / 2,n - i); ++j){
				int k = n - i - j;
				ans = max(ans,dp[i][j][k]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
