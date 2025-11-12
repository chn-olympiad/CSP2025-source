#include <bits/stdc++.h>
using namespace std;
#define baolinle pair<long long >
long long n,m,k;
long long u,v,w;
long long hxy[10001][11],ans;
long long mp[10001][10001];
bool vis[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(mp,0x3f3f3f3f,sizeof mp);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		int minn=0x3f3f3f3f,v=-1;
		for(int j=1;j<=n;j++){
			if(minn>mp[i][j]){
				minn=mp[i][j];
				v=j;
			}
		}
		if(v==-1)break;
		vis[v]=1;
		for(int j=1;j<=n;j++){
			if(mp[i][j]>mp[i][v]+mp[v][j]){
				mp[i][j]=mp[i][v]+mp[v][j];
			}
		}
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
