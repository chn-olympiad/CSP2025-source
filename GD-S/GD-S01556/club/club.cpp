#include <bits/stdc++.h>
using namespace std;
const int N=205, M=1e5+5;
int t, n, dp[N][N][N], b[M], ans;
struct Data{
	int y[3];
	bool operator<(Data b)const{
		return y[0]-y[1] < b.y[0]-b.y[1];
	}
}a[M];
inline void chkmax(int &x, int y){
	x = x<y?y:x;
}
inline bool checka(){
	for(int i=1; i<=n; ++i)
		if(a[i].y[1]!=0 || a[i].y[2]!=0) return false;
	return true;
}
inline void solvea(){
	for(int i=1; i<=n; ++i) b[i] = a[i].y[0];
	sort(b+1, b+1+n);
	for(int i=n; i>n/2; --i) ans += b[i];
	printf("%d\n", ans);
}
inline bool checkb(){
	for(int i=1; i<=n; ++i)
		if(a[i].y[2] != 0) return false;
	return true;
}
inline void solveb(){
	sort(a+1, a+1+n);
	for(int i=1; i<=n/2; ++i) ans += a[i].y[1];
	for(int i=n/2+1; i<=n; ++i) ans += a[i].y[0];
	printf("%d\n", ans);
}
inline void solve(){
	ans = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d", &a[i].y[0], &a[i].y[1], &a[i].y[2]);
	if(checka()){
		solvea();
		return;
	}
	if(checkb()){
		solveb();
		return;
	}
	for(int i=0; i<=n/2; ++i)
		for(int j=0; j<=n/2; ++j)
			for(int k=0; k<=n/2&&i+j+k<=n; ++k)
				dp[i][j][k] = 0;

	for(int i=0; i<=n/2; ++i)
		for(int j=0; j<=n/2; ++j)
			for(int k=0; k<=n/2&&i+j+k<=n; ++k){
				if(i > 0) chkmax(dp[i][j][k], dp[i-1][j][k]+a[i+j+k].y[0]);
				if(j > 0) chkmax(dp[i][j][k], dp[i][j-1][k]+a[i+j+k].y[1]);
				if(k > 0) chkmax(dp[i][j][k], dp[i][j][k-1]+a[i+j+k].y[2]);
				if(i+j+k == n) chkmax(ans,dp[i][j][k]);
			}
	printf("%d\n", ans);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) solve();
//	fflush(stdout);
//	system("fc club.out club4.ans");
	return 0;
}
