#include<bits/stdc++.h>
using namespace std;
int n,m,tot,mod=998244353,c[505],ans[505];
bool vis[505];
string s;
void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=c[ans[i]]||s[i-1]=='0'){
				sum++;
			}
		}
		if(n-sum>=m) tot++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		ans[x]=i;
		dfs(x+1);
		vis[i]=false;
		ans[x]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<tot;
	return 0;
}
