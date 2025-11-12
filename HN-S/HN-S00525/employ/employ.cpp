#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],ans=0,d[510];
char c[510];
bool vis[510];
void dfs(int step,int sum,int cnt){
	if(cnt<m){
		return;
	}
	if(step>n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,sum+(c[step]=='0'||sum>=a[i]),cnt-(sum>=a[i]||c[step]=='0'));
			vis[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,n);
	cout<<ans;
	return 0;
}
