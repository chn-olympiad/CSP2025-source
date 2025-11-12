#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define mod 998244353
#define lowbit(x) ((x) -(x))

const int N = 505;
string s;
bool vis[N];
int f[N][N],p[N],c[N],n,m,ans;
void solve(){
	int cnt = 0,xcnt = 0;
	for(int i = 1;i <= n;i++){
		if(xcnt >= c[p[i]]) xcnt++;
		else{
			if(s[i] == '0') xcnt++;
			else cnt++;
		}
	}
	ans+=(cnt >= m);
	ans%=mod;
}
void dfs(int k){
	if(k > n){
		solve();
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		p[k] = i;
		vis[i] = true;
		dfs(k+1);
		vis[i] = false;
	}
}
void rundp(){
	f[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < i;j++){ 
			for(int p = 1;p <= i;p++){
				if(i-1-j >= c[p]) f[i][j]+=f[i-1][j];
				else{
					if(s[i] == '0') f[i][j]+=f[i-1][j];
					else f[i][j+1]+=f[i-1][j];
				}
				f[i][j]%=mod;
				f[i][j+1]%=mod;
			}
		}
	}
	int ans = 0;
	for(int i = m;i <= n;i++) (ans+=f[n][i]%mod)%mod;
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s = " " + s;
	int cnt = 0;
	for(int i = 1;i <= n;i++) cnt+=(s[i] == '1');
	for(int i = 1;i <= n;i++) cin>>c[i];
	if(cnt < m){
		cout<<0;
		return 0;
	}
	if(cnt == n){//A
		int ans = 1;
		for(int i = 1;i <= n;i++) ans = ans * i % mod;
		cout<<ans % mod;
		return 0;
	}
	if(n <= 12){
		dfs(1);
		cout<<ans;
	}else rundp();
	return 0;
}
