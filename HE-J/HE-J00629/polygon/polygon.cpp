#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans[5005],cnt,mod = 998244353;
void dfs(int x){
	if(x > n){
		int maxn = -1e9,sum = 0,tmp = 0;
		for(int i = 1;i <= n;i++){
			if(ans[i] == 1){
				sum += a[i];
				maxn = max(maxn,a[i]);
				tmp++;
			}
		}
		if(tmp < 3)return;
		if(sum > maxn * 2){
			cnt = (cnt + 1) % mod;
		}
		return;
	}
	ans[x] = 1;
	dfs(x + 1);
	ans[x] = 0;
	dfs(x + 1);
}
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	dfs(1);
	cout << cnt << endl;
	return 0;
}
