#include<bits/stdc++.h>
using namespace std;
int c[505];
int p[505];
int cnt;
int vis[505];
int n,m;
int d[505];
bool judge(){
	int ps=0,fl=0;
	for(int i=1;i<=n;i++){
		if(fl>=c[p[i]]) fl++;
		else if(d[i]) ps++;
		else fl++;
	}
	return ps>=m;
}
void dfs(int u){
	if(u==n+1){
		if(judge()){
			cnt++;
			// for(int i=1;i<=n;i++) cout<<p[i]<<' '; cout<<'\n';
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[u]=i;
		vis[i]=1;
		dfs(u+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch; cin>>ch;
		if(ch=='1') d[i]=1;else d[i]=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1); cout<<cnt;
	return 0;
}