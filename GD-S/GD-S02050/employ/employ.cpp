#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 6;
const int mod = 998244353;
void read(int& x){
	x = 0; int f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch == '-') f = -1;
	for(;isdigit(ch);ch=getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
	x *= f; 
}
void print(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x%10+48);
}
int n,m,ti[N],jie[N],ans;
bool isdif[N],vis[N];
void dfs(int cur,int ac){
	if(cur == n){
		if(ac >= m) ans++;
		if(ans >= mod) ans -= mod;
		return;
	}
	if(ac >= m){
		ans += jie[n-cur];
		if(ans >= mod) ans -= mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i] = true;
		if(isdif[i] or cur - ac >= ti[i]) dfs(cur+1,ac);
		else dfs(cur+1,ac+1);
		vis[i] = false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n); read(m);
	jie[0] = 1;
	for (int i = 1; i <= n; ++i) jie[i] = (jie[i-1] * i) % mod;
	std::string s; std::cin >> s;
	for (int i = 0; i < n; ++i){
		char ch = s[i];
		if(ch == '0') isdif[i+1] = true;
		else isdif[i+1] = false;
	}
	for (int i = 1; i <= n; ++i) read(ti[i]);
	dfs(0, 0);
	print(ans);
	return 0;
}