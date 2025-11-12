#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 5005,p = 998244353;
int n,a[N];
ll ans,f[N],g[N];

void solve() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	f[0] = g[0] = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = a[i] + 1;j <= a[n] + 1;j++) ans = (ans + f[j]) % p;
		for(int j = 0;j <= a[n] + 1;j++) {
			int x = min(a[n] + 1,a[i] + j);
			g[x] = (g[x] + f[j]) % p;
		}
		for(int j = 0;j <= a[n] + 1;j++) f[j] = g[j]; 
	}
	printf("%lld",ans);
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}