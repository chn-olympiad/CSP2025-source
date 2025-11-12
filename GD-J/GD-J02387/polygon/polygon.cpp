#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline long long read(){
	long long f = 0,k = 0;
	char c = getchar();
	while(!isdigit(c)){
		f |= c == '-';
		c = getchar();
	}
	while(isdigit(c)){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f ? -k : k;
}
long long n,a[5005],ans,c[5005][5005];
bool vis[2 << 21];
void dfs(long long r,long long u,long long maxn,long long sum,long long tot,long long now){
	if(tot >= 3){
		if(maxn * 2 < sum && !vis[now]){
			++ans;
			ans %= mod;
			vis[now] = 1;
		}
	}
	if(u < 1) return ;
	for(int i = u - 1;i >= 1;i--){
		long long cur = now | (1 << (i - 1));
		if(!vis[cur]){
			dfs(r,i,max(maxn,a[i]),sum + a[i],tot + 1,cur);
		}
		dfs(r,i,maxn,sum,tot,now);
	}
}
void init(){
	for(int i = 1;i <= n;i++){
		c[i][1] = i,c[i][i] = 1;
	}
	for(int i = 3;i <= n;i++){
		for(int j = 2;j < i;j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= mod;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = read();
	bool fl = 0;
	for(int i = 1;i <= n;i++){
		a[i] = read();
		if(a[i] > 1) fl = 1;
	}
	if(!fl){//È«ÊÇ1 
		init();
		long long tot = 0;
		for(int i = 3;i <= n;i++){
			tot = (tot + c[n][i]) % mod;
		}
		printf("%lld",tot);
		return 0;
	}
	sort(a + 1,a + 1 + n);
	ans = 0ll;
	for(int i = 1;i <= n;i++){
		dfs(i,i,a[i],a[i],1,(long long)(1 << (i - 1)));
	}
	printf("%lld",ans % mod);
	return 0;
}
