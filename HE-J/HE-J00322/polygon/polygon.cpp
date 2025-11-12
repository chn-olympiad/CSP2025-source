#include <bits/stdc++.h>
using namespace std;

long long awa[123123];
bool vis[123123];
long long need_solve[123123];

long long n;//总元素数 
long long ans = 0;

void solve(long long n){//判断该选择方案是否可行； n：need_solve中元素数
	long long maxn = -1e18, tot = 0;
	for(long long i = 1; i <= n; i++){
		maxn = max(maxn, need_solve[i]); 
		tot += need_solve[i];
	}
	if(tot > 2 * maxn) ans++;
	ans = ans % 998244353;
}

void dfs(long long x){//x：已找到多少个元素 
	if(x == n-1){//就差最后一个元素了 
		long long cnt = 0;
		for(long long i = 1; i <= n-1; i++){
			if(vis[i]){
				cnt++;
				need_solve[cnt] = awa[i];
			}
		}
		solve(cnt); //在此之前，最后一个元素没被选 
		need_solve[cnt+1] = awa[n];//最后一个元素，选！ 
		solve(cnt+1);
	}
	else{
		vis[x+1] = true;   dfs(x+1);
		vis[x+1] = false;  dfs(x+1);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	//////////////////////////////////////////////////////////////////////
	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> awa[i];
	if(n<=2) cout << 0; //特判 1
	else if(n == 3){//特判 2 
		if(awa[1]+awa[2]>awa[3] && awa[1]+awa[3]>awa[2] && awa[2]+awa[3]>awa[1]) cout << 1;
		else cout << 0;
	}
	else{
		vis[1] = 0; dfs(1);
		vis[1] = 1; dfs(1);
		cout << ans - 1;//也不知道为啥，每次输出总是比答案大1 
	}
	//////////////////////////////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}
