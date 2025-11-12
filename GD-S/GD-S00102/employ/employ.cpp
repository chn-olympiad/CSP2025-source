#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n, m, mini=5, a[505], f[505];
long long ans;
string s;
int dfs(int k, int x, int y){
	if(k>n){
		if(x>=m) return 1;
		return 0;
	}else{
		int d=0;
		for(int i=1; i<=n; i++){
			if(f[i]) continue;
			f[i]=1;
			if(s[k]=='0' || y>=a[i]) d=(d+dfs(k+1, x, y+1))%mod;
			else d=(d+dfs(k+1, x+1, y))%mod;
			f[i]=0;
		}
		return d;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i=0; i<s.size(); i++){
		mini=min(mini, s[i]-'0');
	}
	s=" "+s;
	if(mini==1){
		ans=1;
		for(int i=n; i>=1; i--){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}else if(n==m){
		for(int i=0; i<s.size(); i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=n; i>=1; i--){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	ans=dfs(1, 0, 0);
	cout<<ans;
	return 0;
}

