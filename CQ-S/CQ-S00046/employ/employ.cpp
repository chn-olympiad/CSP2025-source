#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n,m;
char c[505];
bool vis[505],qqqq = 1;
long long ans,a[505],d[505],jcx[505],cnt;
void sou(int x){
	//if(oK + n - x < m) return;
	if(x == n+1){
		int qfr = 0;
		for(int i = 1;i <= n;++i){
			if(qfr >= a[d[i]]) ++qfr;
			else if(c[i] == '0') ++qfr;
		}
		if(n-qfr < m) return;
		++ans;
		if(ans == MOD) ans = 0;
		return;
	}
	for(int i = 1;i <= n;++i){
		if(vis[i] == 1) continue;
		vis[i] = 1,d[x] = i;
		sou(x+1);
		vis[i] = 0,d[x] = 0;
	}
}
void sou2(int x,int qfr){
	if(x-1 >= m){
		ans = (ans + jcx[n-x-qfr]) % MOD;
		return;
	}
	if(x + qfr == n+1) return;
	for(int i = 1;i <= n;++i){
		if(vis[i] == 1) continue;
		vis[i] = 1,d[x] = i;
		if(qfr >= a[i] || c[x] == '0') sou2(x,qfr+1);
		else sou2(x+1,qfr);
		vis[i] = 0,d[x] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	jcx[1] = 1;
	for(int i = 2;i <= n;++i) jcx[i] = (jcx[i-1] * i) % MOD;
	for(int i = 1;i <= n;++i) cin >> c[i];
	for(int i = 1;i <= n;++i) if(c[i] == '0') qqqq = 0;
	for(int i = 1;i <= n;++i) cin >> a[i];
	if(n <= 12) sou(1);
	else sou(2);
	cout << ans;
	return 0;
}
