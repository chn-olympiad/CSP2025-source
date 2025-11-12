#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
void dfs(int x,int tmax,int sum,int cnt){
	if(x == n + 1){
		ans++;
		ans %= 998244353;
		return;
	}
	if(tmax * 2 < sum && cnt >= 3) dfs(x + 1,tmax,sum,cnt);
	sum += a[x];
	tmax = min(tmax,a[x]);
	if(tmax * 2 < sum && cnt >= 2) dfs(x + 1,tmax,sum,cnt + 1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(1,0,0,0);
	cout << ans << endl;
	return 0;
}

