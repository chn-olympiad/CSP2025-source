#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10011][10011];
int c[10011];
int d[10011][10011];
int dis[10011];
int vis[10011];
int vis1[10011][11];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(a,0x3f,sizeof(a));
	memset(dis,0x3f,sizeof(dis));
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w,a[v][u]=w;
	}
	bool flag=true;
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	if(k==0){
		int ans=0;
		vis[1]=1;
		int tot=1;
		int nowpos=1;
		while(tot<n){
			for(int i=1;i<=n;i++) dis[i]=min(dis[i],a[nowpos][i]);
			int minpos=0,minval=0x3f3f3f3f;
			for(int i=1;i<=n;i++){
				if(vis[i]>0) continue;
				if(i==nowpos) continue;
				if(minval>dis[i]) minpos=i,minval=dis[i];
			}
			//cout<<minpos<<" "<<minval<<'\n';
			nowpos=minpos,ans+=minval,tot++,vis[nowpos]=1;
			dis[nowpos]=0;
		}
		cout<<ans<<'\n';
		return 0;
	}
		for(int i=1;i<=n;i++){
			for(int l=1;l<=k;l++){
				a[i][n+l]=d[l][i],a[n+l][i]=d[l][i];
			}
		}
		int ans=0;
		vis[1]=1;
		int tot=1;
		int nowpos=1;
		while(tot<n){
			for(int i=1;i<=n+k;i++) dis[i]=min(dis[i],a[nowpos][i]);
			int minpos=0,minval=0x3f3f3f3f;
			for(int i=1;i<=n+k;i++){
				if(vis[i]>0 and i<=n) continue;
				if(i>n and vis1[nowpos][i-n]==1) continue;
				if(i==nowpos) continue;
				if(minval>dis[i]) minpos=i,minval=dis[i];
			}
			if(minpos>n) vis1[nowpos][minpos-n]=1;
			else vis[minpos]=1;
			nowpos=minpos,ans+=minval;
			dis[nowpos]=0;
			if(nowpos<=n) tot++;
			//cout<<nowpos<<'\n';
		}
		cout<<ans<<'\n';
		return 0;
	return 0;
}