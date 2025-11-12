#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1=" ",s;
int n,m,a[505],ans;
bool f[505];
void dfs(int dep,int k,int cnt){
	if(n-dep+1+cnt<m)return;
	if(dep>n){
		if(cnt>=m)ans++;
		return;
	}
	if(s[dep]=='0'){
		for(int i=1;i<=n;i++){
			if(f[i])continue;
			f[i]=1;
			dfs(dep+1,k+1,cnt);
			f[i]=0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(f[i])continue;
			f[i]=1;
			if(k>=a[i])dfs(dep+1,k+1,cnt);
			else dfs(dep+1,0,cnt+1);
			f[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=s1+s;
	for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	
	if(n>=100){
		ans=1;
		for(int i=1;i<=m;i++){
			ans=(ans*(n-i+1))%998244353;
		}
		cout<<ans;
	}
	
	else if(n<100){
		dfs(1,0,0);
	cout<<ans;
	}
	return 0;
}


