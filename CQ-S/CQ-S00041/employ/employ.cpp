#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[50005],a[50005],bjA,vis[50005],sta[50005],bre[50005],ans;
string s;
void dfs(int dep){
	if(dep==n+1){
		int re=0,co=0;
		for(int i=1;i<=n;i++) {
			bre[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(bre[i]) continue;
			if(a[sta[i]]<=re) {
				re++,bre[i]=1;
				continue;
			}
			if(s[i-1]=='0'){
				int st=re;
				bre[i]=1;
				re++;
			}else{
				bre[i]=1;
				co++;
			}
		}
		if(co>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		sta[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
	return ;
}
void solve1(){
	dfs(1);
	cout<<ans<<"\n";
	return ;
}
void solve2(){
	if(!bjA){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			cout<<"0\n";
			return ;
		}
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	cout<<ans<<"\n";
	return ;
}
void solve3(){
}
signed main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bjA=1;
	for(int i=0;i<s.length();i++) {
		if(s[i]!='1') {
			bjA=0;
			break;
		}
	}
	if(n<=18) solve1();
	else if(m==n) solve2();
	else if(bjA) solve3();
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/














































//不过在考场上祈祷会不会把考运给抽走呢？ 
