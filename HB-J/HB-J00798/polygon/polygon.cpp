#include <bits/stdc++.h>
using namespace std;
int n, a[5000];
namespace slove1{
	bool vis[25] = {0}, fail[25] = {0};
	long long ans = 0;
	int dfs(int step, int sum, int mxl, int last){
		int mx;
		if(step == n + 1) return 0;
		for(int i = last + 1; i <= n; i++){
			if(!vis[i] && !fail[i]){
				if(step < 3){
					vis[i] = 1;
					dfs(step + 1, sum + a[i], max(mxl, a[i]), i);
					vis[i] = 0;
					continue;
				}
				mx = max(mxl, a[i]);
				if(sum + a[i] > 2 * mx) ans++;
				vis[i] = 1;
				dfs(step + 1, sum + a[i], mx, i);
				vis[i] = 0;
			}
		}
		return ans % 998244353;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(n <= 20) cout << slove1::dfs(1, 0, 0, 0);
}
