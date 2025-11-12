#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans = 0;
const int maxn = 1e5 + 5;
int a[maxn][3];
bool vis[maxn];
void dfs(int t,int la,int lb,int lc,int u,int k) {
//	cout << t << " " << la << " " << lb << " "<< lc << " " << u << endl; 
	if(k == n + 1) {
		ans = max(ans,t);
		return;
	}
	for(int i = 1;i <= u;i++) {
		if(la < n / 2 && !vis[i]) {
			vis[i] = true;
			dfs(t + a[i][1],++la,lb,lc,u,++k);
			la -= 1;
			k -= 1;
			vis[i] = false;
		}
		if(lb < n / 2 && !vis[i]) {
			vis[i] = true;
			dfs(t + a[i][2],la,++lb,lc,u,++k);
			lb -= 1;
			k -= 1;
			vis[i] = false;
		} 
		if(lc < n / 2 && !vis[i]) {
			vis[i] = true;
			dfs(t + a[i][3],la,lb,++lc,u,++k);
			lc -= 1;
			k -= 1;
			vis[i] = false;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		dfs(0,0,0,0,n,1);
		cout << ans << endl;
	}
	return 0;
}
