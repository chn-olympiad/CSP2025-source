# include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
const int N = 5 * 1e4 + 5;  
int n,ans;
int a[N];
int aa[N];
void dfs(int x,int prev,int sum,int mx){
	if(prev == x){
		if(sum > 2 * mx){
			ans++;
		}
		return;
	}
	for(int i = prev + 1;i <= n;i++){
			aa[prev + 1] = a[i];
			dfs(x,i,sum + a[i],max(mx,a[i]));	
	}
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 3;i <= n;i++){
		dfs(i,0,0,0);
		ans = ans % mod;
	}
	cout << ans % mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 