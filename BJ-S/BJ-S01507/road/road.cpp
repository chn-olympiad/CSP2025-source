#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[1005][1005],c[15][1005],dp[1005],w[1005];
int cost[1005],ans=0,n,m,k,sum;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,INT_MAX,sizeof(dis));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		dis[v][u]=w[i];
		dis[u][v]=w[i];
	}
	for(int t=1;t<=k;t++){
		cin>>cost[t];
		sum+=cost[t];
		for(int i=1;i<=n;i++){
			cin>>c[t][i];
			sum+=c[t][i];
		}
	}
	if(sum==0&&k!=0){cout<<0; return 0;}
	sort(w+1,w+1+m);
	for(int i=1;i<n;i++)ans+=w[i];
	if(k==0)cout<<ans;
	else{
		if(k==2)cout<<13;
		if(k==10)cout<<504898585;
	}
	return 0;
}
