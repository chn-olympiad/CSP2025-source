#include<bits/stdc++.h>
using namespace std;
int n,m,q[505],c[505],vis[505],fA;
string s;
const int Mod=998244353;
long long ans; 
inline void dfs(int x){
	if(x==n+1){
		int qx=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') qx++;
			else if(qx>=c[q[i]]) qx++; 
		}
		if(n-qx>=m) ans=(ans+1)%Mod;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) {
			vis[i]=1;
			q[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
} 
int w;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;for(int i=0;i<n;i++) if(s[i]=='0') w++; 
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n-w<m) {
		cout<<0;
		return 0;
	}
	dfs(1);cout<<ans;
	return 0;
}
/*
25pts
*/

