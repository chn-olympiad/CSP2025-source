#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1005];
bool s[505];
int c[505];
int ans;
int x[505];
int vis[505];
int check(){
	int u=0,d=0;
	for(int i=1;i<=n;i++){
		int now=x[i];
		if(!s[i]){
			d++;
			continue;
		}
		if(d>=c[now]){
			d++;
			continue;
		}
		
		u++;
	}
	return u;
}
void dfs(int d){
	if(d>n){
		if(check()>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		x[d]=i;
		dfs(d+1);
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='1') s[i]=1;
		else s[i]=0;
	} 
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
