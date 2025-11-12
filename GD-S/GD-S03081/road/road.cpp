#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,K,u,v,w,c,a,d[1145][1145],ans=0,mp[1145][1145];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=n+K;i++)
		for(int j=1;j<=n+K;j++)
			mp[i][j]=-1;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=n+1;i<=n+K;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
			mp[i][j]=mp[j][i]=a;
		}
	}
	for(int i=1;i<=n+K;i++)
		for(int j=1;j<=n+K;j++)
			d[i][j]=1e9,d[j][j]=0;
	for(int k=1;k<=n+K;k++)
		for(int i=1;i<=n+K;i++)
			for(int j=1;j<=n+K;j++){
				if(mp[i][k]>-1&&mp[k][j]>-1) d[i][j]=min(d[i][j],min(d[i][k]+mp[k][j],d[k][j]+mp[i][k]));
			}
	for(int i=1;i<=n+K;i++)
		for(int j=1;j<=n+K;j++)
			ans+=d[i][j];
	cout<<ans/2;
	return 0;
}
