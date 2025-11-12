#include<bits/stdc++.h>
using namespace std;
int n,m,k,mp[10010][10010],u,v,w,c,a,dp[10020],te;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(mp,0x7f,sizeof mp);
	dp[0]=mp[0][0];
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>dp[n+i];
		for(int j=1;j<=n;j++){
			cin>>a;
			mp[i+n][j]=a;
			mp[j][i+n]=a;
		}
	}
	cout<<dp[5]+mp[1][5]+mp[5][3];
	for(int i=1;i<=n;i++){
		int min1=1;
		te=0;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(mp[i][j]<mp[i][min1]&&mp[i][j]<dp[te]+mp[i][te]+mp[j][te]){
				min1=j;
				for(int l=n+1;l<=n+k;l++){
					
					if(dp[l]+mp[i][l]+mp[l][min1]<mp[i][min1]&&dp[l]+mp[i][l]+mp[l][min1]<dp[te]+mp[i][te]+mp[min1][te]){
						cout<<0<<"\n";
						te=l;
					}
				}
			}
		}
		if(min1==i) continue;
		if(te>n) ans+=dp[te],dp[te]=0;
		if(te>n) ans+=mp[te][min1],mp[te][min1]=0;
		cout<<i<<" "<<min1<<" "<<mp[i][min1]<<"\n";
		cout<<i<<" "<<te<<" "<<mp[i][te]<<"\n";
		if(te>n) ans+=mp[i][te],mp[i][te]=0;
		else ans+=mp[i][min1],mp[i][min1]=0;
		for(int j=1;j<=n;j++){
			if(mp[min1][j]==0) mp[i][j]=0,mp[j][i]=0;
		}
		if(te>n){
			for(int j=1;j<=n;j++){
				if(mp[te][j]==0) mp[i][j]=0,mp[j][i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
