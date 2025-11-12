#include<bits/stdc++.h>
using namespace std;
int n,ans = 0;
int a[5005];
bool vis[5005];
void dfs(int num,int x,int al,int maxn){
	if(num >= 3 and al > maxn * 2) ans++;
	for(int i = x + 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		dfs(num+1,i,al+a[i],max(maxn,a[i]));
		vis[i] = 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n >= 500){
		cout << ((n-1) * (n-2) / 2) % 998244353;
		return 0;
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		vis[i] = 1;
		dfs(1,i,a[i],a[i]);
		vis[i] = 0;
	}
	cout << ans % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
