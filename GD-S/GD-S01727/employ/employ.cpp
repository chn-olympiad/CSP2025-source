#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int p[15];
int a[15];
string s;
int n,m;
int vis[15];
int ans;
void dfs(int d){
	if(d==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') cnt++;
			else if(a[p[i]]<=cnt) cnt++;
			else sum++;
		}
		ans+=sum>=m;
		if(ans>=P) ans-=P; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1,p[d]=i;
		dfs(d+1);
		vis[i]=p[d]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans<<'\n';
}
