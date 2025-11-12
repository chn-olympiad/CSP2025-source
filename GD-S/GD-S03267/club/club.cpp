#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,n;
ll ans;
ll a[100005][5];
ll f[205][205][205],f1[205][205][205];
struct dd {
	int a,b,c;
} ;
bool cmp (dd a,dd b) {
	return a.c > b.c;
}
void dfs (int aa,int b,int c,int sum,int x) {
	if (aa > n / 2 || b > n / 2 || c > n / 2) return;
	if (x == n + 1) {
		return;
	}
	dfs (aa + 1,b,c,sum + a[x][1],x + 1);
	dfs (aa,b + 1,c,sum + a[x][2],x + 1);
	dfs (aa,b,c + 1,sum + a[x][3],x + 1);
}
inline void solve () {
	ans = 0;
	memset (f,0,sizeof(f));
	memset (f1,0,sizeof(f1));
	scanf("%d",&n);
	int aa = 0,bb = 0,cc = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%lld",&a[i][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) aa += a[i][1];
			if (j == 2) bb += a[i][2];
			if (j == 3) cc += a[i][3];
		}
	}
	if (bb == 0 && cc == 0) {
		priority_queue<int>q;
		for (int i = 1; i <= n; i++) q.push(a[i][1]);
		for (int i = n,j = 1; i >= 1,j <= n / 2; i--,j++) ans += q.top(),q.pop();
		cout << ans << endl;
		return;
	}
	if (cc == 0) {
		dd g[100005] = {0};
		int t = 0;
		for (int i = 1; i <= n; i++) {
			g[i].a = a[i][1],g[i].b = a[i][2],g[i].c = a[i][1] - a[i][2];
		}
		sort (g + 1,g + n + 1,cmp);
		for (int i = 1; i <= n; i++) {
//			cout << g[i].a << " " << g[i].b << " " << g[i].c << endl;
			if (i <= n / 2) ans += g[i].a;
			else ans += g[i].b;
		}
		cout << ans << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(n / 2,i); j++) {
			for (int k = 0; k <= min(n / 2,i); k++) {
				if (j + k > i) break;
				for (int l = 0; l <= min(n / 2,i); l++) {
					if (j + k + l > i) break;
					if (j) f[j][k][l] = max(f1[j - 1][k][l] + a[i][1],f[j][k][l]);
					if (k) f[j][k][l] = max(f1[j][k - 1][l] + a[i][2],f[j][k][l]);
					if (l) f[j][k][l] = max(f1[j][k][l - 1] + a[i][3],f[j][k][l]);
				}
			}
		}
		for (int j = 0; j <= min(n / 2,i); j++) {
			for (int k = 0; k <= min(n / 2,i); k++) {
				if (j + k > i) break;
				for (int l = 0; l <= min(n / 2,i); l++) {
					if (j + k + l > i) break;
					f1[j][k][l] = f[j][k][l];
				}
			}
		}
	}
	for (int j = 0; j <= n / 2; j++) {
		for (int k = 0; k <= n / 2; k++) {
			for (int l = 0; l <= n / 2; l++) {
				if (j + k + l > n) break;
				ans = max(ans,f[j][k][l]);
			}
		}
	}
//	dfs (0,0,0,0,1);
	printf("%lld\n",ans);
	return;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}
