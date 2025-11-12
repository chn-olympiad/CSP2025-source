#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N];
string s;
inline void solve1(){
	int ans=1;
	for(int i=1;i<=n;i++) (ans*=i)%=mod;
	//for(int i=1;i<=n;i++) cout << c[i] << " ";
	cout << ans << "\n";
	return;
}
bool vis[N];
int num[N];
inline bool check(){
	int tot=0,fail=0;
	for(int i=1;i<=n;i++){
		//cout << num[i] << " ";
		if(fail>=c[num[i]]) fail+=1;
		else if(s[i]=='0') fail+=1;
		else tot+=1;
	}
	//cout << "\n";
	if(tot>=m) return true;
	return false;
}
int ans=0;
inline void dfs(int dep){
	if(dep==n+1){
		//for(int i=1;i<=n;i++) cout << num[i] << " ";
		//cout << "\n";
		if(check()) ans+=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		num[dep]=i;
		vis[i]=1;
		dfs(dep+1);
		vis[i]=0;
	}
	return;
}
inline void solve2(){
	dfs(1);
	cout << ans << "\n";
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> s,s=' '+s;
	for(int i=1;i<=n;i++) cin >> c[i];
	sort(c+1,c+n+1);
	if(n<=10) {
		solve2();
		return 0;
	}
	int t=0;
	for(int i=1;i<=n;i++) if(s[i]=='1') t++; 
	if(t==n) {
		solve1();
		return 0;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
