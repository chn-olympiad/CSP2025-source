#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[505],jc[505],dp[2][1<<20][25],pos[505],pre[505],ans,cnt,cnt2;
char s[505];
bool checkA(){
	for (int i = 1;i <= n;i++){
		if (s[i] != '1') return 0;
	}
	return 1;
}
bool checkB(){
	cnt2 = 0;
	for (int i = 1;i <= n;i++) cnt2 += (s[i] == '1');
	return cnt2 <= 18;
}
void clear(int x){
	for (int i = 0;i < (1<<n);i++){
		for (int j = 0;j <= n;j++) dp[x][i][j] = 0;
	}
}
void solve(int x,int y){
	int res = 1;
	for (int i = 1;i <= cnt2;i++) pre[i] = pre[i-1]+pos[i]-pos[i-1]+(!(x>>i-1&1));
	for (int i = cnt2,j = 0;i;i--){
		while (j < n && c[j+1] > pre[i]) j++;
		if (x>>i-1&1) res = res*(j-(cnt2-i))%mod;
	}
	(ans += res*jc[n-y]%mod) %= mod;
}
void planB(){
	int tmp = 0;jc[0] = 1;
	for (int i = 1;i <= n;i++){
		jc[i] = jc[i-1]*i%mod;
		if (s[i] == '1') pos[++tmp] = i; 
	}
	sort(c+1,c+n+1,[](int a,int b){return (a > b);});
	for (int i = 0;i < (1<<cnt2);i++){
		int x = 0,tmp = i;
		while (tmp) x++,tmp -= (tmp&-tmp);
		if (x >= m) solve(i,x);
	}
	cout << ans;
}
signed main(){
	//freopen("D:\\employ\\employ5.in","r",stdin);
	#ifndef LOCAL
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	cin >> n >> m >> (s+1);
	for (int i = 1;i <= n;i++){
		cin >> c[i];
		if (c[i] != 0) cnt++;
	}
	if (cnt < m) return cout << 0,0;
	else{
		dp[0][0][0] = 1;
		for (int i = 1;i <= n;i++){
			clear(i&1);
			for (int j = 1;j <= n;j++){
				for (int k = 0;k < (1<<n);k++){
					if (k&(1<<j-1)) continue;
					for (int x = 0;x <= n;x++){
						if (s[i] == '0' || x >= c[j]) (dp[i&1][k^(1<<j-1)][x+1] += dp[~i&1][k][x]) %= mod;
						else (dp[i&1][k^(1<<j-1)][x] += dp[~i&1][k][x]) %= mod;
					}
				}
			}
		}
		ans = 0;
		for (int i = 0;i <= n-m;i++) (ans += dp[n&1][(1<<n)-1][i]) %= mod;
		cout << ans;
	}
	//for (int i = 1;i <= n;i++) ans = ans*i%mod;
	//cout << ans;
	return 0;
}

