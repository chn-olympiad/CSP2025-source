#include<bits/stdc++.h>
using namespace std;
#define int long long
void st(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int nm=1e6+10;
int n,m,k,ans,cnt,u,v,w;
int val[5100][5100],dis[nm],vis[nm];
int c[nm];
//struct edge{
//	int u,v,val;
//}e[nm];
//bool cmp(edge a,edge b){
//	return a.val<b.val;
//}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	st();
	cin>>n>>m>>k;
//	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].val;
//	sort(e+1,e+m+1,cmp);
	for(int i=0;i<=n+k;i++) dis[i]=LONG_LONG_MAX;
	for(int i=1;i<=n+k;i++) for(int j=1;j<=n+k;j++) val[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		val[u][v]=val[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			val[n+i][j]=val[j][n+i]=w;
		}
	}
	dis[1]=0;
	vis[1]=1;
	cnt++;
	for(int i=1;i<=n+k;i++) dis[i]=min(dis[i],val[1][i]);
	for(int i=2;i<=n+k;i++){
		u=0;
		for(int j=1;j<=n+k;j++){
			if(!vis[j]&&dis[j]<dis[u]) u=j;
		}
		if(u<=n) cnt++;
		vis[u]=1;
		ans+=dis[u];
		if(cnt==n) break;
		for(int j=1;j<=n+k;j++) dis[j]=min(dis[j],val[u][j]);
	}
	cout<<ans;
	//cout<<'\n'<<cnt;
	return 0;
}
