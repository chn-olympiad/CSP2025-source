#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll e=1,v=0;
	char s=getchar();
	while(s<'0'||s>'9') {
		if(s=='-') {
			e=-1;
			s=getchar();
			break;
		} else s=getchar();
	}
	while(s>='0'&&s<='9') {
		v=(v<<3)+(v<<1)+s-'0';
		s=getchar();
	}
	return e*v;
}
ll ans=100000000000,t,n,m,a[10001][10001],k,v,u,w,vis[10001];
inline void dfs(ll uu,ll vi,ll ki){
	if(ki==n){
		if(vi<=ans)ans=vi;
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[uu][i]!=10000000000&&vis[i]==0){
			vis[i]=1;
			dfs(i,vi+a[uu][i],ki+1);
			vis[i]=0;
		}
	}
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=n; j++)
		a[i][j]=10000000000;
	}
	for(int i=1; i<=m; i++) {
		v=read();
		u=read();
		w=read();
		a[v][u]=w;a[u][v]=w;
	}
	for(int i=1;i<=n;i++)dfs(i,0,1);
	cout<<ans;
	return 0;
}
//4 4 2 1 4 6 2 3 7 4 2 5 4 3 4
