#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+10;
const ll M = 998244353;
ll l[N];
ll bi[N];
//ll sum[N];
//ll dp[N][N];

bool vis[N];
int n;
ll dfs(int cur, int sel) {
	if (cur > n) {
		if (sel >= 3) {
			int mi = 0;
			int sum = 0;
			for (int i=1;i<=n;i++) {
				if (vis[i]) {
					mi = i;
					sum += l[i];
				}
			}
			if (sum > bi[mi]) {
				return 1;
			}
		}
		
		return 0;
	}
	ll cnt = 0;
	cnt = (cnt + dfs(cur+1, sel)) % M;
	vis[cur] = true;
	cnt = (cnt + dfs(cur+1, sel+1)) % M;
	vis[cur] = false;
	return cnt;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n); //int*
	for (int i=1;i<=n;i++) { //int = int; int <= int; int++
		scanf("%lld",&l[i]); //ll*
	}
	
	sort(l+1,l+n+1); //ll*, tea*
	for (int i=1;i<=n;i++) { //int = int; int <= int; int++
		bi[i] = l[i]<<1ll; //ll = ll << ll
//		sum[i] = sum[i-1] + l[i]; //ll = ll + ll
	}
	
	printf("%lld\n", dfs(1,0));
	return 0;
}
