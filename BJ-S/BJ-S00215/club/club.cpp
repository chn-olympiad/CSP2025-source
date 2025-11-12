#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, int>
const int MAXN = 1e5+5;

int t, n; ll ans;
ll a[MAXN][4];
ll f[205][205][205];
pi op[MAXN];

int main(){
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n); ans = 0;
		for (int i=1; i<=n; i++) scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
		if (n <= 200){
			for (int i=1; i<=n; i++) for (int j=0; j<=n; j++) for (int k=0; k<=n; k++) f[i][j][k] = 0;
			for (int i=1; i<=n; i++){
				for (int j=0; j<=i; j++){
					for (int k=0; k<=i-j; k++){
						if (j > 0) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k]+a[i][1]);
						if (k > 0) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1]+a[i][2]);
						if (j+k <= i-1) f[i][j][k] = max(f[i][j][k], f[i-1][j][k]+a[i][3]);
					}
				}	
			}
			for (int i=1; i<=n/2; i++){
				for (int j=1; j<=n/2; j++){
					if (n-i-j > n/2) continue;
					ans = max(ans, f[n][i][j]);
				}
			} printf("%lld\n", ans);
			continue;
		}
		for (int i=1; i<=n; i++){
			a[i][2] -= a[i][1]; ans += a[i][1];
			op[i] = {a[i][2], i};
		} sort(op+1, op+n+1);
		for (int i=1; i<=n; i++){
			if (i > n/2 && op[i].first <= 0) break;
			ans += op[i].first;
		} printf("%lld\n", ans);
	}
	return 0;
}