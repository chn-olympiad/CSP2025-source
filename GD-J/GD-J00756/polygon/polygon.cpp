#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int a[5010], n, k, sum[5010];
int dfs(bool is[], int sm, int mx, int mxid, int pre){
	long long res = 0;
	if (sm>2*mx) res++;
	for (int i=pre+1; i<=n; i++){
		if (!is[i]) continue;
		is[i] = false;
		if (i == mxid) {
			int newmxid = mxid-1;
			while (a[newmxid]==0&&newmxid>=1)newmxid--;
			int newmx = a[newmxid];
			if (sm-a[i]>2*newmx){
				res += dfs(is, sm-a[i], newmx, newmxid, i);
				res %= p;
			}
		}else if (sm-a[i]>2*mx){
			res += dfs(is, sm-a[i], mx, mxid, i);
			res %=p;
		}
		is[i] = true;
	}
	return res;
}
bool is[5010];
void solve(){
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i=1; i<=n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	memset(is + 1, true, n);
	cout << dfs(is, sum[n], a[n], n, 0);
} 

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
}
