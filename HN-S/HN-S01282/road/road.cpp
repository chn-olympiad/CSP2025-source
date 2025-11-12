#include<bits/stdc++.h>
using namespace std;
int n,m,k,minn=INT_MAX;
int l[1005][1005];
int cnmd[1005];
int continueside[15][1005],ccost[15];
int u,v,cost;
void dfs(int m,int d,int sum){
	if(d==n){
		minn=min(minn,sum);
	    return;
	}
	for(int i=1;i<=n;i++){
	   if(cnmd[i]||!l[d][i])continue;
	   cnmd[i]=1;
	   dfs(m,d+1,sum+l[d][i]);
	   dfs(i,d+1,sum+l[d][i]);
	   cnmd[i]=0;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>u>>v>>cost;
    	l[u][v]=cost;
    	l[v][u]=cost;
	}
	for(int i=1;i<=k;i++){
		cin>>ccost[i];
		for(int j=1;j<=n;j++){
			cin>>continueside[i][j];
		}
	}
	for(int b=1;b<=n;b++){
		for(int e=b+1;e<=n;e++){
			if(b==e)continue;
			for(int i=1;i<=k;i++){
				l[b][e]=min(l[b][e],continueside[i][b]+continueside[i][e]+ccost[i]);
				l[e][b]=l[b][e];
			}
		}
	}
	cnmd[1]=1;
	dfs(1,1,0);
	cout<<minn;
    return 0;
}
