#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+9;
const int m = 998244353;
typedef long long ll;
int n,a[N];
int ans = 0;
bool vis[N];
void dfs(int u,int k,int s,int mx){
	if(u == n + 1){
		if(k < 3) return;
		int maxn = mx;
		if(s > 2 * maxn){
			ans++;
			ans %= m;
		}
		return;
	}
	dfs(u + 1,k,s,mx);
	vis[u] = 1;
	dfs(u + 1,k + 1,s+a[u],max(mx,a[u]));
	vis[u] = 0;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout << ans % m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

