#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
typedef long long ll;
const int mod=998244353;
bool vis[maxn];
int dis[maxn][maxn];
int iw[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>dis[u][v];
		dis[v][u]=dis[u][v];
	}
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		for(int j=1;j<=n;j++){
			cin>>iw[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],iw[j]+iw[k]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int minw=mod,mink=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(minw>dis[1][j]){
				mink=j;
				minw=dis[1][j];
			}
		}
		vis[mink]=1;
		for(int i=1;i<=n;i++)
			dis[1][i]=dis[mink][i];
		ans+=minw;
	}
	cout<<ans;
}
