#include <bits/stdc++.h>
#define ll long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=2e5+1;
int T, n, a[4][N], mx1, mx2, mx3;
int dp[101][101][101], b[N], ans;
bool cmp(int x,int y) {
	return a[1][x]-a[2][x]>a[1][y]-a[2][y];
}
signed main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		mx1=mx2=mx3=0;
		for (int i=1;i<=n;i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			mx1=max(mx1,a[1][i]);
			mx2=max(mx2,a[2][i]);
			mx3=max(mx3,a[3][i]);
		}
		if (mx2==0&&mx3==0) {
			sort(a[1]+1,a[1]+n+1,greater<int>());
			ans=0;
			for (int i=1;i<=n/2;i++) ans+=a[1][i];
			cout << ans << '\n';
			continue;
		} else if (mx3==0) {
			for (int i=1;i<=n;i++) b[i]=i;
			sort(b+1,b+n+1,cmp);
			ans=0;
			for (int i=1;i<=n/2;i++) ans+=a[1][b[i]];
			for (int i=n/2+1;i<=n;i++) ans+=a[2][b[i]];
			cout << ans << '\n';
			continue;
		}
		memset(dp,0,sizeof(dp));
		ans=0;
		for (int i=1;i<=n;i++) for (int x=n/2;x>=0;x--)
			for (int y=n/2;y>=0;y--) for (int z=n/2;z>=0;z--) {
				if (x>0) dp[x][y][z]=max(dp[x][y][z],dp[x-1][y][z]+a[1][i]);
				if (y>0) dp[x][y][z]=max(dp[x][y][z],dp[x][y-1][z]+a[2][i]);
				if (z>0) dp[x][y][z]=max(dp[x][y][z],dp[x][y][z-1]+a[3][i]);
				ans=max(ans,dp[x][y][z]);
			}
		cout << ans << '\n';
	}
	Blackdream1853 code;
}
/*
2
4
114 514 0
1919 810 0
100 86 0
1853 1314 0
6
114 0 0
514 0 0
1919 0 0
810 0 0
810 0 0
810 0 0
----4372 3539
*/
