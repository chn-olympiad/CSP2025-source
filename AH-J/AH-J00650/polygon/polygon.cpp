#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 5e3+5;
int a[N];
int ans=0;
struct node {
	int maxn;
	int sum;
};
int n;
node dp[5005][5005];
void dfs(int now, int cnt, int value, int maxn) {
	if (cnt<0||now>=n) {
		if (value>2*maxn) ans++;
		return;
	}
	dfs(now+1, cnt-1, value+a[now], max(maxn, a[now]));
	dfs(now+1, cnt-1, value, maxn);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	if (n==3) {
		int sum;
		sum=a[0]+a[1]+a[2];
		if (sum>2*max(max(a[0], a[1]), a[2])) cout << 1;
		else cout << 0;
	} else if (n<=20) {
		for (int i=3; i<=n; i++) {
			dfs(0, i-1, 0, 0);
		}
		cout << ans << endl;
	} else {
		for (int k=3; k<=n; k++) {
			memset(dp, 0, sizeof(dp));
			if (k==n) {
				int maxn=0, sum=0;
				for (int i=0; i<n; i++) sum+=a[i], maxn=max(maxn, a[i]);
				if (sum>2*maxn) ans++;
			}
			for (int i=0; i<n; i++) dp[i][n-1]={0, 0};
			for (int i=0; i<n; i++) dp[i][n-2]={a[i], a[i]};
			for (int i=1; i<n; i++) {
				for (int j=0; j<k; j++) {
					if (j>0) {
						dp[i][j]=dp[i-1][j];
						dp[i][j].sum=dp[i-1][j-1].sum+a[i];
						dp[i][j].maxn=max(dp[i-1][j-1].maxn, a[i]);
					}
				}
			}
			for (int i=0; i<n; i++) {
				for (int j=0; j<k; j++) {
					if (dp[i][j].sum>2*dp[i][j].maxn) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
