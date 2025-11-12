#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 5005;
int ans[maxn],a[maxn];
bool vis[maxn];
int rp = 0;
void dfs(int t,int star,int m) {
	if(t == m + 1) {
		int maxx = 0;
		int sum = 0;
		for(int i = 1; i <= m; i++) {
			maxx = max(maxx,ans[i]);
			sum += ans[i];
		}
		if(sum > maxx * 2) {
			rp++;
		}
		return;
	}
	for(int i = star; i <= n; i++) {
		ans[t] = a[i];
		dfs(t + 1,i + 1,m);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(vis,false,sizeof(vis));
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 3;i <= n;i++) dfs(1,1,i);
	cout << rp << endl;
	return 0;
}

