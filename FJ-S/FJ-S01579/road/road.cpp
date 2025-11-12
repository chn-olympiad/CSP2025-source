#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,u,v,w,s,d,t=1,sum;
bool bj[10001]={1,1};
int edge[10001][10001],a[11][10001],dist[10001];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[u][v]=edge[v][u]=w;
	}
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) cin>>a[i][j];
	for(int i=2;i<=n;i++) dist[i]=1e12;
	for(int i=1;i<=k;i++){			
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
			    if(edge[x][y]) edge[x][y]=min(edge[x][y],a[i][0]+a[i][x]+a[i][y]);
			    else edge[x][y]=a[i][0]+a[i][x]+a[i][y];
		    }
		}		
	}
	for(int i=1;i<n;i++){
		s=1e12;
		for(int j=2;j<=n;j++){
			if(bj[j]) continue;
			if(edge[t][j]) dist[j]=min(dist[j],edge[t][j]);
		}
		for(int j=2;j<=n;j++){
			if(bj[j]) continue;
			if(dist[j]<s){
				s=dist[j];
				d=j;
			}
		}
		t=d;
		bj[t]=1;
	}
	for(int i=2;i<=n;i++) sum+=dist[i];
	cout<<sum;
	return 0;
}
