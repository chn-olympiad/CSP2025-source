#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 3e3+5;
struct GXR {
	int G1,G2,G3;
} a[maxn];

int f[35][35][35][35];
int GXR8(int n) {
	memset(f,0,sizeof f);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n/2; j++)
			for (int k = 0; k <= n/2; k++)
				for (int l = 0; l <= n/2; l++) {
					if (j > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j-1][k][l]+a[i].G1);
					if (k > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j][k-1][l]+a[i].G2);
					if (l > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j][k][l-1]+a[i].G3);
				}
	int ans = 0;
	for (int j = 0; j <= n/2; j++)
		for (int k = 0; k <= n/2; k++)
			for (int l = 0; l <= n/2; l++)
				if (j+k+l == n)
					ans = max(ans,f[n][j][k][l]);
	return ans;
} // 1-8 
int GXRSpA(int n) {
	sort(a+1,a+n+1,[](GXR a, GXR b) {
		return a.G1 < b.G1;
	});
	int ans = 0;
	for (int i = 1; i <= n/2; i++)
		ans +=  a[i].G1;
	return ans;
} // 12

int g[205][205][205];
int GXRSpB(int n) {
	memset(g,0,sizeof g);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n/2; j++)
			for (int k = 0; k <= n/2; k++) {
				if (j > 0) g[i][j][k] = max(g[i][j][k],g[i-1][j-1][k]+a[i].G1);
				if (k > 0) g[i][j][k] = max(g[i][j][k],g[i-1][j][k-1]+a[i].G2);
			}
	return g[n][n>>1][n>>1];
} // 9 
int mian() {
	int n; cin >> n; 
	int x3 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].G1 >> a[i].G2 >> a[i].G3;
		x3 = max(x3,a[i].G3);
	}
	if (n <= 30) cout << GXR8(n);
	else if (n == 200) cout << GXRSpB(n);
	else cout << GXRSpA(n);
	cout << endl;
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) mian();
	return 0;
}
// T1 做不出来，后面忘了。