#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],b[N];
bool vis[N]; 
long long ans;
string s;
void dfs(int x){
	if(x>n){
		int res1=0;
		for(int i=1;i<=n;i++){
			if(a[b[i]]<=res1){
				res1++;
				continue;
			} 
			if(s[i-1]=='0') res1++;
		}
		if(n-res1>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		b[x]=i;
		vis[i]=1;
		dfs(x+1);
		b[x]=0;
		vis[i]=0;
	}
}
bool p(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') return false;
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(p(s)){
		long long res=1;
		for(int i=1;i<=n;i++){
			res=(res*i)%mod;
		}
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
