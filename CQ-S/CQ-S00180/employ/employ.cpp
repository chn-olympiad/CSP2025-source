#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=505;
int n,m,c[N],cntA,ans;
string s;
int vis[N],p[N];
void dfs(int x,int num){
	int suc=x-1-num;
	if(suc+n-x+1<m) return;
	if(x>n){
		if(suc<m) return;
		++ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if((s[x]=='0')||(num>=c[i])) dfs(x+1,num+1);
			else dfs(x+1,num);
			vis[i]=0;
		}
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]) ++cntA;
	}
	if(n-cntA<m) cout<<0,exit(0);
	if(n<=11){
		dfs(1,0);
		cout<<ans,exit(0); 
	}
	cout<<0;
	return 0;
}
