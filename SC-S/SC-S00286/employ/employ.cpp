#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100,MOD = 998244353;
int n,m,c[N],val[N],ans;
bool hd[N],vis[N];
string s;
void dfs(int d,int rem,int lft){
	if(n-d+rem<m) return;
	if(d==n){
		if(rem>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		val[d+1] = i;
		int reca = rem,recb = lft;
		if(lft>=c[val[d+1]] or !hd[d+1]) recb++;
		else reca++;
		dfs(d+1,reca,recb);
		vis[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//freopen("D\\test.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) hd[i+1] = s[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		dfs(0,0,0);
		cout<<ans%MOD;
		return 0;
	}
	if(m==n){
		int flag = 0;
		for(int i=1;i<=n;i++) if(!c[i]) flag = 1;
		for(int i=1;i<=n;i++) if(!hd[i]) flag = 1;
		if(flag) cout<<0;
		else{
			int T = 1;
			for(int i=1;i<=n;i++) T=T*i%MOD;
			cout<<T;
		}
		return 0;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/