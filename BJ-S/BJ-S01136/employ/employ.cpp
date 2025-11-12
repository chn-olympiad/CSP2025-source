#include <iostream>
using namespace std;

int c[505],n,m,ans;
char s[505];

namespace S1_2{
	bool vis[505];
	void dfs(int u,int cnt){
		//cerr << "dfsing " << u << " with cnt " << cnt << endl;
		if(n - cnt < m) return;
		if(u == n + 1){
			ans++;
			return;
		}
		for(int i = 1;i <= n; i++) if(!vis[i]){
			vis[i] = true;
			if(cnt >= c[i] || s[u] == '0') dfs(u+1,cnt+1);
			else dfs(u+1,cnt);
			vis[i] = false;
		}
	}
}

namespace S1t5{
	int dp[20][262145];
	int d(int st,int cnt,int u){
		if(dp[cnt][st]) return dp[cnt][st];
		if(!st) return dp[cnt][st] = (n - cnt >= m ? 1 : 0);
		int ans = 0;
		for(int i = 1;i <= n; i++) if(st & 1 << i - 1)
			if(cnt >= c[i] || s[u] == '0') ans += d(st ^ (1 << i - 1),cnt+1,u+1);
			else ans += d(st ^ (1 << i - 1),cnt,u+1);
		return dp[cnt][st] = ans;
	}
}
			

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool All_1 = true;
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> s[i];
	for(int i = 1;i <= n; i++) cin >> c[i];
	//if(n <= 10) S1_2::dfs(1,0);
	ans = S1t5::d((1<<n)-1,0,1);
	cout << ans % 998244353 << endl;
	
	return 0;
}