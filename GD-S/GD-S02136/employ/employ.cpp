#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int read(){
	int f = 0,k = 0;
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
int n,m,c[505],a[505],ans;
char s[505];
bool vis[505];
void dfs(int u){
	if(u > n){
		int sum = 0,tot = 0;//people no employ now
		for(int i = 1;i <= n;i++){
			if(tot < c[a[i]] && s[i] == '1'){
				++sum;
			}
			else {
				++tot;
			}
		}
		if(sum >= m){
			ans = (ans + 1) % mod;
		}
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		a[u] = i;
		dfs(u + 1);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for(int i = 1;i <= n;i++){
		c[i] = read();
	}
	dfs(1);
	printf("%lld",ans % mod);
	return 0;
}
