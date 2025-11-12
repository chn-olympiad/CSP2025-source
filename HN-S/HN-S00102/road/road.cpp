#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[1000001];
int u,v,w,maxx,minn;
map<int,map<int,int> >mp,mp2,mp3;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
		mp2[u][v]=1;
		mp2[v][u]=1;
		maxx+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>mp3[i][1];
		for(int j=2;j<=n+1;j++){
			cin>>mp3[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		minn+=mp3[i][1];
		for(int j=2;j<=n+1;j++){
			if(mp2[i][j-1]==1){
				if(mp[i][j-1]>mp3[i][j])minn-=(mp[i][j-1]-mp3[i][j]);
				//cout<<i<<" "<<j<<endl;
			}
		}if(minn<0){
			cout<<minn<<endl;
			maxx+=minn;
		}
	}
	cout<<maxx;	
	return 0;
}
